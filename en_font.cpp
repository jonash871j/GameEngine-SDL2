#include "en_font.h"
#include "en_console.h"
#include <string>
#include <iostream>

namespace Engine
{
	Font::Font(cstring fontPath, int32 fontSize)
	{
		this->path = fontPath;
		this->size = fontSize;
		font = TTF_OpenFont(fontPath, fontSize);
		
		if (font == NULL)
		{
			Console::WriteError();
			Console::Write("[SDL_TTF] ");
			Console::Write(TTF_GetError());
			Console::WriteLine();
		}
	}

	Font::~Font()
	{
		TTF_CloseFont(font);
	}
	cstring Font::GetPath()
	{
		return path;
	}
	int32 Font::GetSize()
	{
		return size;
	}
	TTF_Font* Font::GetFont()
	{
		return font;
	}
}

