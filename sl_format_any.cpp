#include "sl_format_any.h"
#include "sl_format_wave.h"
#include "sl_format_raw.h"

#pragma comment(lib, "shlwapi.lib")
#include <Shlwapi.h>
#include <string>

namespace SoundLib
{
	Format* FormatAny::Import(cwstring path)
	{
		std::wstring extention = PathFindExtension(path);

		if (extention == L".wav")
			return new FormatWave(path);
		else
			return new FormatRaw(path);
	}
}
