#pragma once
#include "sl_def.h"

namespace SoundLib
{
	class SL_DLL_OUT Format abstract
	{
	protected:
		uint32 size = 0;
		cwstring path = nullptr;

	protected:
		Extern::E_FileStream* fileStream = nullptr;
		Sound* sound = nullptr;

	public:
		Format();
		~Format();

	protected:
		void ThrowInvalidFile();

	protected:
		uint8 ReadBYTE();
		uint16 ReadWORD();
		uint32 ReadDWORD();
		void ReadSkip(uint32 amount);

	public:
		// Used to import sound file from path
		virtual void Import(cwstring path);

	protected:
		virtual void ImportHeader() = 0;
		virtual void ImportBlocks() = 0;

	public:
		// Used to get sound
		Sound* GetSound();

		// Used to get sound file path
		cwstring GetPath();
	};
}

