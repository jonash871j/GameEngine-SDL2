/* +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+ */
/* |	SoundLib - v31/05/2020	 OO	   OO	 OO    OO    OO	 | */
/* |							O  O  O	 O  O  O  O  O  O  O | */
/* |	By Jonas				    OO	  OO	OO	  OO	 | */
/* +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+ */

#pragma once
#define SL_DLL_OUT

namespace SoundLib
{
	
	typedef unsigned __int64 uint64;
	typedef unsigned __int32 uint32;
	typedef unsigned __int16 uint16;
	typedef unsigned __int8 uint8;

	typedef signed __int64 int64;
	typedef signed __int32 int32;
	typedef signed __int16 int16;
	typedef signed __int8 int8;

	typedef const wchar_t* cwstring;

	typedef class Format Format;
	typedef class FormatAny FormatAny;
	typedef class FormatWave FormatWave;
	typedef class FormatRaw FormatRaw;
	typedef class Sound Sound;
	typedef class SoundDevices SoundDevices;
	typedef class SoundDevice SoundDevice;
	typedef class SoundPlayer SoundPlayer;
	typedef class SoundMixer SoundMixer;

	typedef struct SoundQuality SoundQuality;

	enum class WaveType
	{
		Invalid = 0,
		PCM = 1,

		W1M08 = 0x00000001,
		W1S08 = 0x00000002,
		W1M16 = 0x00000004,
		W1S16 = 0x00000008,
		W2M08 = 0x00000010,
		W2S08 = 0x00000020,
		W2M16 = 0x00000040,
		W2S16 = 0x00000080,
		W4M08 = 0x00000100,
		W4S08 = 0x00000200,
		W4M16 = 0x00000400,
		W4S16 = 0x00000800,
		W44M08 = 0x00000100,
		W44S08 = 0x00000200,
		W44M16 = 0x00000400,
		W44S16 = 0x00000800,
		W48M08 = 0x00001000,
		W48S08 = 0x00002000,
		W48M16 = 0x00004000,
		W48S16 = 0x00008000,
		W96M08 = 0x00010000,
		W96S08 = 0x00020000,
		W96M16 = 0x00040000,
		W96S16 = 0x00080000,
	};

	enum class LoopFlags
	{
		Normal,
		Endless,
	};
}      
namespace SoundLib
{
	namespace Extern
	{
		typedef struct E_Thread E_Thread;
		typedef struct E_FileStream E_FileStream;
		typedef struct E_WAVEFORMATEX E_WAVEFORMATEX;
		typedef struct E_WAVEHDR E_WAVEHDR;
		typedef struct E_HWAVEOUT E_HWAVEOUT;
	}
}