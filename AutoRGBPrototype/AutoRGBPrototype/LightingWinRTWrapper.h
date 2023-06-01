#pragma once

class LightingWinRT
{
public:

	static HRESULT FindClassIDeviceInformationStatics(
		Microsoft::WRL::ComPtr<ABI::Windows::Devices::Enumeration::IDeviceInformationStatics>& deviceInformationStatics);

	static HRESULT FindClassILampArrayStatics(
		Microsoft::WRL::ComPtr<ABI::Windows::Devices::Lights::ILampArrayStatics>& lampArrayStatics);

	static HRESULT FindClassILampArrayEffectPlaylistStatics(
		Microsoft::WRL::ComPtr<ABI::Windows::Devices::Lights::Effects::ILampArrayEffectPlaylistStatics>& lampArrayEffectPlaylistStatics);

	static HRESULT ActivateInstanceILampArrayEffectPlaylist(
		Microsoft::WRL::ComPtr<ABI::Windows::Devices::Lights::Effects::ILampArrayEffectPlaylist>& lampArrayEffectPlaylist);

	static HRESULT FindClassILampArrayCustomEffectFactory(
		Microsoft::WRL::ComPtr<ABI::Windows::Devices::Lights::Effects::ILampArrayCustomEffectFactory>& lampArrayCustomEffectFactory);

	static HRESULT FindClassIColorHelperStatics(
		Microsoft::WRL::ComPtr<ABI::Windows::UI::IColorHelperStatics>& colorHelperStatics);
};
