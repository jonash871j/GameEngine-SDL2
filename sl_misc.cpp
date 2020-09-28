#include "sl_misc.h"
#include <math.h>

namespace SoundLib
{
	namespace Misc
	{
		uint32 FloatToUInt32(float value)
		{
			uint32 whole = (uint32)floorf(value);
			uint32 decimal = uint32((value - whole) * 0xF000);
			return (whole << 16) ^ decimal;
		}
		uint16 FloatToUInt16(float value)
		{
			uint16 whole = (uint32)floorf(value);
			uint16 decimal = uint16((value - whole) * 0xF0);
			return (whole << 8) ^ decimal;
		}
		float UInt16ToFloat(uint32 value)
		{
			return 0.0f;
		}
	}
}