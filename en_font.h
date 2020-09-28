#pragma once
#include "en_def.h"
#include "SDL_ttf.h"

namespace Engine
{
	class Font
	{	
		friend class Draw;
	private:
		cstring path;
		int32 size;

	private:
		TTF_Font* font;

	public:
		Font(cstring fontPath, int32 fontSize);
		~Font();

	public:
		cstring GetPath();
		int32 GetSize();
		TTF_Font* GetFont();
	};
}