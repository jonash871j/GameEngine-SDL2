#include "sl_sound_quality.h"

namespace SoundLib
{
	SoundQuality::SoundQuality(uint16 bitsPerSample, uint32 sampleRate, uint16 channels, WaveType type)
		: bitsPerSample(bitsPerSample), sampleRate(sampleRate), channels(channels), type(type) {}
	SoundQuality::~SoundQuality(){}
}