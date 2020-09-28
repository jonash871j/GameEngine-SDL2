#include "en_def.h"

#include "SDL_timer.h"

namespace Engine
{
	void Core::Delay(uint duration)
	{
		SDL_Delay(duration);
	}
}
