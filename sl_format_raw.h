#pragma once
#include "sl_format.h"
#include "sl_sound_quality.h"

namespace SoundLib
{
	class SL_DLL_OUT FormatRaw : public Format
	{
	private:
		SoundQuality quality;

	public:
		FormatRaw();
		FormatRaw(cwstring path);
		FormatRaw(cwstring path, SoundQuality quality);

	public:
		void Import(cwstring path, SoundQuality quality);

	private:
		virtual void ImportHeader() override;
		virtual void ImportBlocks() override;
	};
}

