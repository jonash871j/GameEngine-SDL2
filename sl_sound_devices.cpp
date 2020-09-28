#include "sl_sound_devices.h"
#include "sl_sound_device.h"
#include "sl_misc.h"

#pragma comment(lib, "winmm.lib")
#include <Windows.h>

namespace SoundLib
{
	SoundDevices::SoundDevices()
	{
		WAVEOUTCAPS woc;

		amount = waveOutGetNumDevs();

		for (uint32 i = 0; i < amount; i++)
			if (waveOutGetDevCaps(i, &woc, sizeof(WAVEOUTCAPS)) != S_OK)
				amount--;

		soundDevices = new SoundDevice*[amount];
		for (uint32 i = 0; i < amount; i++)
			if (waveOutGetDevCaps(i, &woc, sizeof(WAVEOUTCAPS)) == S_OK)
				soundDevices[i] = new SoundDevice(woc.szPname, woc.wMid, woc.wPid, woc.vDriverVersion, 
					woc.dwFormats, woc.wChannels, woc.wReserved1, woc.dwSupport, i);
	}
	SoundDevices::~SoundDevices()
	{
		delete[] soundDevices;
	}

	uint32 SoundDevices::GetAmount()
	{
		return amount;
	}
	SoundDevice** SoundDevices::GetDevices()
	{
		return soundDevices;
	}
	SoundDevice* SoundDevices::GetDevice(uint32 i)
	{
		return soundDevices[i];
	}
	SoundDevice* SoundDevices::GetDefaultDevice()
	{
		return soundDevices[0];
	}
}