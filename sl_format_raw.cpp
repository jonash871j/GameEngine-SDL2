#include "sl_format_raw.h"
#include "sl_sound.h"
#include "sl_ec_file_stream.h"

#include <windows.h>

namespace SoundLib
{
	FormatRaw::FormatRaw(){}

	FormatRaw::FormatRaw(cwstring path)
	{
		Format::Import(path);
	}

	FormatRaw::FormatRaw(cwstring path, SoundQuality quality)
		: quality(quality)
	{
		Format::Import(path);
	}

	void FormatRaw::Import(cwstring path, SoundQuality quality)
	{
		this->quality = quality;
		Format::Import(path);
	}

	void FormatRaw::ImportHeader()
	{
		LARGE_INTEGER lSize = { 0 };
		HANDLE hPath = CreateFile(path, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
		GetFileSizeEx(hPath, &lSize);

		size = (uint32)lSize.QuadPart;
		sound = new Sound(quality);
	}

	void FormatRaw::ImportBlocks()
	{
		uint8* buffers = new uint8[size];
		fileStream->inFile.read(buffers, size);
		sound->CreateBuffers(buffers, size);
	}
}
