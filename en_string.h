#pragma once
#include "en_def.h"

namespace Engine
{
	struct String
	{
	private:
		char* charArray;
		int32 index;
		int32 length = 0;

	public:
		String(String& string);
		String(cstring text);
		String(char character);

	public:
		const char* GetCharArray();

	public:
		String operator+ (cstring text);

	private:
		void Extend(cstring add, int32 length);
		//String(const String& string)


	};
}


