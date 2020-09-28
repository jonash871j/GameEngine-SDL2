#pragma once
#include "sl_def.h"

namespace SoundLib
{
	namespace Misc
	{
		// Used to delete 2d object from memory
		template<typename T>
		static void Delete2D(uint32 sizeAmount, T** object)
		{
			for (uint32 j = 0; j < sizeAmount; j++)
			{
				delete object[j];
			}
			delete[] object;
		}

		// Converts 1.5f to somthing like this 0x00018000U
		uint32 FloatToUInt32(float value);

		// Converts 1.5f to somthing like this 0x1800U
		uint16 FloatToUInt16(float value);

		float UInt16ToFloat(uint32 value);
	}
}