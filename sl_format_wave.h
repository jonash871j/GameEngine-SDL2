#pragma once
#include "sl_format.h"

namespace SoundLib
{
	class SL_DLL_OUT FormatWave : public Format
	{
	private:
		uint32 formatChunk = 0;
		uint32 formatDataLength = 0;
		uint32 dataSectionSize = 0;
		uint32 sizeDataSection = 0;

	public:
		FormatWave();
		FormatWave(cwstring path);

	private:
		virtual void ImportHeader() override;
		virtual void ImportBlocks() override;
	};
}

