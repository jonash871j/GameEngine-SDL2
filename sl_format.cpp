#include "sl_format.h"
#include "sl_sound.h"
#include "sl_ec_file_stream.h"

#include <vcruntime_exception.h>
#include <stdlib.h>

namespace SoundLib
{
	Format::Format()
	{
		fileStream = new Extern::E_FileStream();
	}
	Format::~Format()
	{
		if (sound != nullptr)
			delete sound;
		if (fileStream != nullptr)
			delete fileStream;
	}

	void Format::ThrowInvalidFile()
	{
		std::string errorString = (char*)path;
		throw std::exception((errorString + " was invalid...\n").c_str());
	}

	uint8 Format::ReadBYTE()
	{
		uint8 byte = 0;
		fileStream->inFile.read(&byte, 1);
		return byte;
	}
	uint16 Format::ReadWORD()
	{
		uint8 bytes[2];
		fileStream->inFile.read(bytes, 2);
		return (bytes[1] << 8) | (bytes[0]);
	}
	uint32 Format::ReadDWORD()
	{
		uint8 bytes[4];
		fileStream->inFile.read(bytes, 4);
		return (bytes[3] << 24) | (bytes[2] << 16) | (bytes[1] << 8) | (bytes[0]);
	}
	void Format::ReadSkip(uint32 amount)
	{
		for (uint32 i = 0; i < amount; i++)
			ReadBYTE(); 
	}
	void Format::Import(cwstring path)
	{
		this->path = path;

		if (sound != nullptr)
			sound->~Sound();

		fileStream->inFile = std::basic_ifstream<uint8>(path, std::ifstream::binary);

		if (fileStream->inFile.fail())
		{
			std::string errorString = (char*)path;
			throw std::exception(("Could't open " + errorString + "\n").c_str());
		}

		ImportHeader();
		ImportBlocks();

		fileStream->inFile.close();
	}
	Sound* Format::GetSound()
	{
		return sound;
	}
	cwstring Format::GetPath()
	{
		return path;
	}
}