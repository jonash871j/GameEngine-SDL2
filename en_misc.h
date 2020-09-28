#pragma once
#include "en_def.h"

namespace Engine
{
	namespace Misc
	{
		// Math
		float Sign(float x);

		// Usefull
		void Toggle(bool& x);

		// Randomness
		float Random(float min, float max);
		int32 Random(int32 min, int32 max);
		float Seed(uint32 seed);
	}
}
