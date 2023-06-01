#include "pch.h"
#include "LightingWinRTWrapper.h"

using namespace ABI::Windows::Foundation;
using namespace ABI::Windows::Devices::Enumeration;
using namespace ABI::Windows::Devices::Lights;
using namespace ABI::Windows::Devices::Lights::Effects;
using namespace ABI::Windows::UI;
using namespace Microsoft::WRL;
using namespace Microsoft::WRL::Wrappers;


HRESULT LightingWinRT::FindClassIDeviceInformationStatics(ComPtr<IDeviceInformationStatics>& deviceInformationStatics)
{
	return GetActivationFactory(
		HStringReference(RuntimeClass_Windows_Devices_Enumeration_DeviceInformation).Get(), 
		&deviceInformationStatics);
}

HRESULT LightingWinRT::FindClassILampArrayStatics(ComPtr<ILampArrayStatics>& lampArrayStatics)
{
	return GetActivationFactory(
		HStringReference(RuntimeClass_Windows_Devices_Lights_LampArray).Get(), 
		&lampArrayStatics);
}

HRESULT LightingWinRT::FindClassILampArrayEffectPlaylistStatics(ComPtr<ILampArrayEffectPlaylistStatics>& lampArrayEffectPlaylistStatics)
{
	return GetActivationFactory(
		HStringReference(RuntimeClass_Windows_Devices_Lights_Effects_LampArrayEffectPlaylist).Get(), 
		&lampArrayEffectPlaylistStatics);
}

HRESULT LightingWinRT::ActivateInstanceILampArrayEffectPlaylist(ComPtr<ABI::Windows::Devices::Lights::Effects::ILampArrayEffectPlaylist>& lampArrayEffectPlaylist)
{
	return ActivateInstance(
		HStringReference(RuntimeClass_Windows_Devices_Lights_Effects_LampArrayEffectPlaylist).Get(), 
		&lampArrayEffectPlaylist);
}

HRESULT LightingWinRT::FindClassILampArrayCustomEffectFactory(ComPtr<ILampArrayCustomEffectFactory>& lampArrayCustomEffectFactory)
{
	return GetActivationFactory(
		HStringReference(RuntimeClass_Windows_Devices_Lights_Effects_LampArrayCustomEffect).Get(), 
		&lampArrayCustomEffectFactory);
}

HRESULT LightingWinRT::FindClassIColorHelperStatics(ComPtr<IColorHelperStatics>& colorHelperStatics)
{
	return GetActivationFactory(
		HStringReference(RuntimeClass_Windows_UI_ColorHelper).Get(), 
		&colorHelperStatics);
}
