#pragma once
#include "en_def.h"
namespace Engine
{
	namespace Console
	{
		void NextLine();

		void WriteErrorLine(cstring _message, void* _pointer);
		void WriteErrorLine(void* pointer);
		void WriteError();
		void WriteLine();
		void WriteLine(cstring message);
		void WriteLine(int value);
		void WriteLine(uint value);
		void WriteLine(float value);

		void Write(cstring message);
		void Write(int value);
		void Write(uint value);
		void Write(float value);
	}
}