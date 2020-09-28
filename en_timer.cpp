#include "en_timer.h"

#include "en_ec_thread.h"
#include <chrono>
#include <vector>
#include <iostream>

namespace Engine
{
	using namespace EncapsulationClasses;

	typedef struct Packet
	{
		uint32 id;
		uint32 ms;
		Timer::State* state;
	}Packet;
	static uint globalId = 0;
	static std::vector<Packet> packets;

	static void SetValue(Packet packet)
	{
		for (uint32 i = 0; i < packets.size(); i++)
		{
			if (packets[i].id == packet.id)
			{
				packets[i] = packet;
				return;
			}
		}
	}
	static Packet GetValue(uint32 id)
	{
		for (uint32 i = 0; i < packets.size(); i++)
		{
			if (packets[i].id == id)
			{
				return packets[i];
			}
		}
	}
	static void RemoveValue(uint32 id)
	{
		for (uint32 i = 0; i < packets.size(); i++)
		{
			if (packets[i].id == id)
			{
				packets.erase(packets.begin() + i);
			} 
		}
	}

	Timer::Timer()
	{
		id = globalId;
		globalId++;
		packets.push_back(Packet{ id, 0, nullptr });
	}
	Timer::~Timer()
	{
		ResetTimer();
		RemoveValue(id);
	}
	void Timer::StartTimer(uint32 ms)
	{
		if (timerState == State::Ready)
		{ 
			SetValue(Packet{ id, ms, &timerState });
			timerThread = std::make_unique<std::thread>(TimerThreadFunction, id);
		}
	}
	void Timer::ResetTimer()
	{
		if (!timerThread)
			return;

		if (timerThread->joinable())
			timerThread->detach();
		timerState = State::Ready;
	}
	void Timer::ResetTimerWhenDone()
	{
		if (timerState == State::Done)
			ResetTimer();
	}
	Timer::State Timer::GetTimerState()
	{
		return timerState;
	}
	void Timer::TimerThreadFunction(const uint32 id)
	{
 		Packet packet = GetValue(id);
		*packet.state = State::Active;
 		std::this_thread::sleep_for(std::chrono::milliseconds(packet.ms));
		*packet.state = State::Done;
 	}
}

