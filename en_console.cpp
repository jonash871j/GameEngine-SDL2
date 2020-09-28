#include "en_console.h"
#include <iostream>

namespace Engine
{
	static int lineNumber = 0;
	static bool lineStart = true;

	static void Write_LineNumber()
	{
		if (lineStart == true)
			std::cout << lineNumber << "> ";
		lineStart = false;
	}
	static void AddLineNumber()
	{
		lineNumber++;
		lineStart = true;
	}


	void Console::WriteError()
	{
		Write_LineNumber();
		printf("\033[1;31m");
		std::cout << "[ERROR] ";
		printf("\033[0m");
	}

	void Console::NextLine()
	{
		AddLineNumber();
	}

	void Console::WriteErrorLine(cstring message, void* pointer)
	{
		if (pointer == nullptr)
		{
			WriteError();
			std::cout << message << '\n';
			AddLineNumber();
		}
	}

	void Console::WriteErrorLine(void* pointer)
	{
		if (pointer == nullptr)
		{
			WriteError();
			std::cout << "Some type was null pointer!" << '\n';
			AddLineNumber();
		}
	}

	void Console::WriteLine()
	{
		Write_LineNumber();
		std::cout << '\n';
		AddLineNumber();
	}

	void Console::WriteLine(cstring message)
	{
		Write_LineNumber();
		std::cout << message << '\n';
		AddLineNumber();
	}

	void Console::WriteLine(int value)
	{
		Write_LineNumber();
		std::cout << value << '\n';
		AddLineNumber();
	}

	void Console::WriteLine(uint value)
	{
		Write_LineNumber();
		std::cout << value << '\n';
		AddLineNumber();
	}

	void Console::WriteLine(float value)
	{
		Write_LineNumber();
		std::cout << value << '\n';
		AddLineNumber();
	}

	void Console::Write(cstring message)
	{
		Write_LineNumber();
		std::cout << message;
	}

	void Console::Write(int value)
	{
		Write_LineNumber();
		std::cout << value;
	}

	void Console::Write(uint value)
	{
		Write_LineNumber();
		std::cout << value;
	}

	void Console::Write(float value)
	{
		Write_LineNumber();
		std::cout << value;
	}
}