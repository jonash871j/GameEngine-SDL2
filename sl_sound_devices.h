#pragma once
#include "sl_def.h"

namespace SoundLib
{
	class SL_DLL_OUT SoundDevices
	{
	private:
		uint32 amount;
		SoundDevice** soundDevices = nullptr;

	public:
		SoundDevices();
		~SoundDevices();

	public:
		uint32 GetAmount();
		SoundDevice** GetDevices();
		SoundDevice* GetDevice(uint32 i);
		SoundDevice* GetDefaultDevice();
	};
}

