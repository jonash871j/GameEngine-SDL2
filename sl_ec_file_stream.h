#pragma once
#include "sl_def.h"
#include <fstream>

namespace SoundLib
{
	namespace Extern
	{
		struct E_FileStream
		{
			std::basic_ifstream<uint8> inFile;
			~E_FileStream() {};
		};
	}
}