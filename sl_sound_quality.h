#pragma once
#include "sl_def.h"

namespace SoundLib
{
	struct SL_DLL_OUT SoundQuality
	{
		uint16 bitsPerSample;
		uint32 sampleRate;
		uint16 channels;
		WaveType type;

		SoundQuality(uint16 bitsPerSample = 16, uint32 sampleRate = 44100, uint16 channels = 2, WaveType type = WaveType::PCM);
		~SoundQuality();
	};
}