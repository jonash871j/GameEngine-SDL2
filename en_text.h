#pragma once
#include "en_def.h"

namespace Engine
{
	class Text
	{	
		friend class Draw;
	private:
		Font* font = nullptr;
		SDL_Surface* sdl_surface;
		SDL_Texture* sdl_texture = nullptr;
		SDL_Color* sdl_color = nullptr;

	private:
		cstring text = "null";
		int32 size = 0;
		int32 width = 0;

	public:
		Text(Font* font);
		~Text();

	public:
		void SetText(cstring text);
		void SetColor(uint8 red, uint8 green, uint8 blue, uint8 alpha = 255);

	public:
		cstring GetText();
		int32 GetSize();
		int32 GetWidth();
	};
}