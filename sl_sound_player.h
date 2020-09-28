#pragma once
#include "sl_def.h"

namespace SoundLib
{
	class SL_DLL_OUT SoundPlayer
	{
	private:
		bool isLoadedFromSoundPlayer = false;
		bool isPlaying = false;
		bool isSoundWaiting = false;

	private:
		uint32 id;
		int32 loopAmount;

	private:
		SoundDevices* soundDevices = nullptr;
		SoundDevice* soundDevice = nullptr;
		Sound* sound = nullptr;
		Format* format = nullptr;

	private:
		Extern::E_Thread* soundThread = nullptr;
		Extern::E_WAVEHDR* waveHeader = nullptr;
		Extern::E_HWAVEOUT* waveOut = nullptr;
		Extern::E_WAVEFORMATEX* waveFormat = nullptr;

	public:
		SoundPlayer(SoundDevice* soundDevice = nullptr);

		// Used to change sound for preloaded sound
		SoundPlayer(Sound* sound, SoundDevice* soundDevice = nullptr);

		// Used to change sound for preloaded sound
		SoundPlayer(Format* format, SoundDevice* soundDevice = nullptr);

		// Used to load any sound file from a path
		SoundPlayer(cwstring path, SoundDevice* soundDevice = nullptr);

		~SoundPlayer();

	public:
		// Used to change sound for preloaded sound
		void Change(Sound* sound);
		
		// Used to change sound for preloaded sound
		void Change(Format* format);

		// Used to load any sound file from a path
		void Load(cwstring path);

	public:
		// Used to play sound 
		void Play();

		// Used to loop sound
		void Loop(LoopFlags flags, uint32 amount = 1);

		// Used to replay sound from the beginning
		void Replay();

		// Used to pause the playing sound
		void Pause();

		// Used to resume paused sound
		void Resume();

		// Used to stop the sound completely
		void Stop();

	public:
		// Used to set the playback rate, works from 0.5x to 2.0x
		void Speed(float speed);

	public:
		// Used to change output sound device
		void SetSoundDevice(SoundDevice* soundDevice);

		// Used to set position index in sound
		void SetPositionIndex(uint32 index);

		// Used to set position in seconds, in sound
		void SetPosition(uint32 position);

	public:		
		// Used to get the sound active state
		bool GetSoundActive();

		// Used to get current loop index, -1 means endless
		int32 GetLoopIndex();

		// Used to get the amount of loops left, -1 means endless
		int32 GetLoopAmount();
		
		// Used to get current position index in sound
		uint32 GetPositionIndex();

		// Used to get current position in seconds, in sound
		uint32 GetPosition();

		// Used to get size of sound
		uint32 GetSize();

		// Used to get time amount of sound
		uint32 GetTimeAmount();

	private:
		// Used to play sound
		void PlayInternal();

		// Used to stop sound
		void StopInternal();

	private:
		// Used alocates new memory for waveHeaders and filling out the structure
		void CreateWaveHeaders();

		// Used alocates new memory for waveOut and filling out the structure
		void CreateWaveOut();

		// Used alocates new memory for waveFormat, filling out the structure and open sound device for playback
		void CreateWaveFormat();

	private:
		// Used to set default sound device
		void SetDefaultSoundDevice();

	private:
		// Used to delete sound data: waveHeader, waveOut & waveFormat
		void DeleteSoundData();

	private:
		// Used to send sound data to soundcard
		static void SendToSoundCard(const uint32 id);
	};
}