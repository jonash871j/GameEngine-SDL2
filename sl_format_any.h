#pragma once
#include "sl_def.h"

namespace SoundLib
{
	static class SL_DLL_OUT FormatAny
	{
	public:
		/// <summary>
		/// Used to import any sound file from path
		/// </summary>
		/// <param name="path"></param>
		/// <returns>
		/// <para/>sound file
		/// <para/> raw sound file if not supported
		/// </returns>
		static Format* Import(cwstring path);
	}FormatAny;
}

