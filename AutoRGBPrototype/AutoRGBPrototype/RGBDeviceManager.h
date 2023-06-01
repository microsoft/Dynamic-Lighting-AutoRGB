#pragma once

struct RGBColor
{
	uint32_t a;
	uint32_t r;
	uint32_t g;
	uint32_t b;

	RGBColor(uint32_t A, uint32_t R, uint32_t G, uint32_t B) :
		a(A), r(R), g(G), b(B)
	{

	}
};

struct LightingDevice
{
	std::wstring _id;
	std::wstring _name;
	INT32 _lampCount;

	ABI::Windows::Devices::Lights::ILampArray* _lampArray;
	ABI::Windows::Devices::Lights::Effects::ILampArrayEffectPlaylist* _playlist;
	ABI::Windows::Devices::Lights::Effects::ILampArrayCustomEffect* _effect;

	std::vector<int32_t> _indices;
	std::vector<ABI::Windows::Devices::Lights::ILampInfo*> _lampInfoList;

	LightingDevice() {}
};

class RGBDeviceManager
{
public:
	RGBDeviceManager() {}
	virtual ~RGBDeviceManager() {}

	HRESULT Initialize();
	HRESULT InitializeWinRT();

	void GetLampArray(
		const Microsoft::WRL::Wrappers::HString& id,
		ABI::Windows::Devices::Lights::ILampArray** lampArray);

	void GetDeviceInformation(
		const Microsoft::WRL::Wrappers::HString& id,
		ABI::Windows::Devices::Enumeration::IDeviceInformation** deviceInfo);

	HRESULT OnDeviceAdded(
		ABI::Windows::Devices::Enumeration::IDeviceWatcher* watcher, 
		ABI::Windows::Devices::Enumeration::IDeviceInformation* deviceInfo);

	HRESULT OnDeviceRemoved(
		ABI::Windows::Devices::Enumeration::IDeviceWatcher* watcher, 
		ABI::Windows::Devices::Enumeration::IDeviceInformationUpdate* info);

	void ChangeColor(uint8_t r, uint8_t g, uint8_t b);

private:
	Microsoft::WRL::ComPtr<ABI::Windows::Devices::Enumeration::IDeviceInformationStatics> m_deviceInfoStatics;
	Microsoft::WRL::ComPtr<ABI::Windows::Devices::Lights::ILampArrayStatics> m_lampArrayStatics;
	Microsoft::WRL::ComPtr<ABI::Windows::Devices::Lights::Effects::ILampArrayCustomEffectFactory> m_effectFactory;
	Microsoft::WRL::ComPtr<ABI::Windows::Devices::Lights::Effects::ILampArrayEffectPlaylistStatics> m_effectPlaylistStatics;
	Microsoft::WRL::ComPtr<ABI::Windows::UI::IColorHelperStatics> m_colorHelperStatics;

	ABI::Windows::UI::Color m_currentColor;
	ABI::Windows::UI::Color m_colorClear;

	std::map<std::wstring, LightingDevice> m_lightingDevices;
	Microsoft::WRL::ComPtr<ABI::Windows::Devices::Enumeration::IDeviceWatcher> m_deviceWatcher;
};


