#include "sl_sound_device.h"

namespace SoundLib
{
	SoundDevice::SoundDevice(cwstring productName, uint32 mid, uint32 pid, uint32 driverVersion, 
		uint32 formats, uint32 channels, uint32 reserved, uint32 support, int32 deviceId)
		: productName(productName), mid(mid), pid(pid), driverVersion(driverVersion),
			formats(formats), channels(channels), reserved(reserved), support(support), deviceId(deviceId){}

	SoundDevice::~SoundDevice() {}

	cwstring SoundDevice::GetProductName()
	{
		return productName;
	}
	uint32 SoundDevice::GetMid()
	{
		return mid;
	}
	uint32 SoundDevice::GetPid()
	{
		return pid;
	}
	uint32 SoundDevice::GetDriverVersion()
	{
		return driverVersion;
	}
	uint32 SoundDevice::GetFormats()
	{
		return formats;
	}
	uint32 SoundDevice::GetChannels()
	{
		return channels;
	}
	uint32 SoundDevice::GetReserved()
	{
		return reserved;
	}
	uint32 SoundDevice::GetSupport()
	{
		return support;
	}
	uint32 SoundDevice::GetDeviceId()
	{
		return deviceId;
	}
}