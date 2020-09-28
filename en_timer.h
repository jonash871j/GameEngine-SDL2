#pragma once
#include "en_def.h"
#include <memory>
#include <thread>

namespace Engine
{
	class Timer
	{
	public:
		enum class State
		{
			Ready,
			Active,
			Done,
		};

	private:
		uint32 id;
		State timerState = State::Ready;
		std::unique_ptr<std::thread> timerThread = nullptr;
		//EncapsulationClasses::E_Thread* timerThread = nullptr;

	public:
		Timer();
		~Timer();

	public:
		void StartTimer(uint32 ms);
		void ResetTimer();
		void ResetTimerWhenDone();

	public:
		State GetTimerState();

	private:
		static void TimerThreadFunction(const uint32 id);
	};
}

