#pragma once
#include "en_def.h"
#include <thread>

namespace Engine
{
	namespace EncapsulationClasses
	{
		struct E_Thread
		{
			std::thread t;
			~E_Thread()
			{
			
			};
		};
	}
}