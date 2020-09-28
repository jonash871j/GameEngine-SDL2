#include "sl_sound.h"
#include <memory>

namespace SoundLib
{
	Sound::Sound()
	{
	}
	Sound::Sound(uint8 bitsPerSample, uint32 sampleRate, uint8 channels, WaveType type)
	{
		SetSoundQuality(bitsPerSample, sampleRate, channels, type);
	}

	Sound::Sound(SoundQuality quality)
		: quality(quality){}

	Sound::~Sound()
	{
		delete[] buffers;
	}
	void Sound::CreateBuffers(uint8* buffers, uint32 size)
	{
		this->size = size;
		this->buffers = buffers;

		// Write zero to last hundred bytes to avoid clicking when sound stops
		for (uint32 i = 0; i < 500; i += 1)
			buffers[size - 500 + i] = 0;
	}
	void Sound::SetValue(uint32 index, uint8 value)
	{
		buffers[index] = value;
	}
	uint32 Sound::GetValue(uint32 index)
	{
		return buffers[index];
	}
	void Sound::SetSoundQuality(uint8 bitsPerSample, uint32 sampleRate, uint8 channels, WaveType type)
	{
		quality.bitsPerSample = bitsPerSample;
		quality.sampleRate = sampleRate;
		quality.channels = channels;
		quality.type = type;
	}
	void Sound::SetSoundQuality(SoundQuality quality)
	{
		this->quality = quality;
	}
	uint8* Sound::GetBuffers()
	{
		return buffers;
	}
	uint32 Sound::GetSize()
	{
		return size;
	}
	SoundQuality* Sound::GetSoundQuality()
	{
		return &quality;
	}
}