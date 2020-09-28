#include "en_text.h"
#include "en_font.h"

#include "SDL.h"
#include <string>

namespace Engine
{
	Text::Text(Font* font)
	{
		this->font = font;

		sdl_color = new SDL_Color();
		sdl_color->r = 255;
		sdl_color->g = 255;
		sdl_color->b = 255;
		sdl_color->a = 255;

		SetText(text);
	}

	Text::~Text()
	{
		SDL_FreeSurface(sdl_surface);
		SDL_DestroyTexture(sdl_texture);

		if (sdl_color != nullptr)
			delete sdl_color;
	}

	void Text::SetText(cstring text)
	{
		this->text = text;
		size = (int32)strlen(text);

		int count = 0;
		int countMax = 0;;

		for (int i = 0; i < size; i++)
		{
			if (text[i] == '\n')
			{
				if (count > countMax)
					countMax = count;
				count = 0;
				continue;
			}
			count++;
		}
		if (count > countMax)
			countMax = count;

		width = countMax * font->GetSize();

		SDL_FreeSurface(sdl_surface);
		sdl_surface = TTF_RenderText_Blended_Wrapped(font->GetFont(), text, *sdl_color, width);
	}
	void Text::SetColor(uint8 red, uint8 green, uint8 blue, uint8 alpha)
	{
		sdl_color->r = red;
		sdl_color->g = green;
		sdl_color->b = blue;
		sdl_color->a = alpha;

		SDL_FreeSurface(sdl_surface);
		sdl_surface = TTF_RenderText_Blended_Wrapped(font->GetFont(), text, *sdl_color, width);
	}
	cstring Text::GetText()
	{
		return text;
	}
	int32 Text::GetSize()
	{
		return size;
	}
	int32 Text::GetWidth()
	{
		return width;
	}
}