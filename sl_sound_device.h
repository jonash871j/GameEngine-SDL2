#pragma once
#include "sl_def.h"

namespace SoundLib
{
	class SL_DLL_OUT SoundDevice
	{ 
		friend class SoundDevices;
	private:
		cwstring productName;
		uint32 mid;
		uint32 pid;
		uint32 driverVersion;
		uint32 formats;
		uint32 channels;
		uint32 reserved;
		uint32 support;
		int32 deviceId;

	private:
		SoundDevice(cwstring productName, uint32 mid, uint32 pid, uint32 driverVersion, 
			uint32 formats, uint32 channels, uint32 reserved, uint32 support, int32 deviceId);

	public:
		~SoundDevice();

	public:
		cwstring GetProductName();
		uint32 GetMid(); 
		uint32 GetPid(); 
		uint32 GetDriverVersion();
		uint32 GetFormats();   
		uint32 GetChannels();
		uint32 GetReserved();   
		uint32 GetSupport();
		uint32 GetDeviceId();
	};
}