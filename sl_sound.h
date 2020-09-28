#pragma once
#include "sl_def.h"
#include "sl_sound_quality.h"

namespace SoundLib
{
	class SL_DLL_OUT Sound
	{ 
	private:
		uint8* buffers = nullptr;
		uint32 size = 0;
		SoundQuality quality;

	public:
		Sound();

		// Used to set sound quality
		Sound(uint8 bitsPerSample, uint32 sampleRate, uint8 channels, WaveType type);

		// Used to set sound quality
		Sound(SoundQuality quality);

		~Sound();

	public:
		// Used to set sound buffer array
		void CreateBuffers(uint8* buffers, uint32 size);

		// Used to set value in buffer array
		void SetValue(uint32 index, uint8 value);

		// Used to get value in buffer array
		uint32 GetValue(uint32 index);

		// Used to set sound quality
		void SetSoundQuality(uint8 bitsPerSample, uint32 sampleRate, uint8 channels, WaveType type);

		// Used to set sound quality
		void SetSoundQuality(SoundQuality quality);

	public:
		// Used to get sound buffer array
		uint8* GetBuffers();

		// Used to get size of buffer
		uint32 GetSize();

		// Used to get SoundQulity structure
		SoundQuality* GetSoundQuality();
	};
}