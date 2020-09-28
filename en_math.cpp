#include "en_misc.h"
#include <stdlib.h>

namespace Engine
{
	float Misc::Sign(float x)
	{
		if (x > 0) x = 1;
		if (x < 0) x = -1;
		return x;
	}

	void Misc::Toggle(bool& x)
	{
		if (!x) x = true;
		else    x = false;
	}

	float Misc::Random(float min, float max)
	{
		float b = (rand() % (int32(max + 1) - int32(min))) + min;
		return b + static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
	}
	int32 Misc::Random(int32 min, int32 max)
	{
		return (rand() % (max + 1 - min)) + min;
	}
	float Misc::Seed(uint32 seed)
	{
		srand(seed);
		return 0.0f;
	}
}