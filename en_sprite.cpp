#include "en_sprite.h"

#include "en_window.h"
#include "en_console.h"
#include "en_misc.h"

#include "SDL_image.h"
#include "SDL.h"


namespace Engine
{
	Sprite::Sprite(Window* _window, cstring _path, Vector2D _vector, float _angle, uint32 _frameWidth, uint32 _frameDelay)
		: window(_window), vector(_vector), angle(_angle), path(_path), frameDelay(_frameDelay)
	{
		isAnimated = true;
		SDL_Surface* sdl_surfaceTemp = IMG_Load(_path);
		if (!CheckSurfaceLoaded(sdl_surfaceTemp))
			sdl_surfaceTemp = SDL_CreateRGBSurface(SDL_SWSURFACE, 64, 64, 32, 0, 0, 0, 0);
		
		// TODO ERROR CHECKING...

		// Logic
		frameAmount = sdl_surfaceTemp->w / _frameWidth;
		
		//
		if (frameAmount <= 0)
		{
			g_error_occurred = true;
			Console::WriteError();
			Console::Write("Not enough space for frames with sprite: ");
			Console::Write(_path);
			Console::Write(", Frame width: ");
			Console::Write(_frameWidth);
			Console::Write(", Sprite width: ");
			Console::WriteLine(sdl_surfaceTemp->w);
		}
		
		//
		width = _frameWidth;
		height = sdl_surfaceTemp->h;

		//
		sdl_surfaceArray = new SDL_Surface*[frameAmount];
		sdl_textureArray = new SDL_Texture*[frameAmount];

		//
		for (uint32 i = 0; i < frameAmount; i++)
		{
			sdl_surfaceArray[i] = SDL_CreateRGBSurfaceWithFormat(0, width, height, 32, SDL_PIXELFORMAT_ABGR32);
			SDL_SetSurfaceBlendMode(sdl_surfaceArray[i], SDL_BLENDMODE_BLEND);

			for (uint32 y = 0; y < height; y++)
				for (uint32 x = 0; x < width; x++)
					SetPixel(sdl_surfaceArray[i], x, y, GetPixel(sdl_surfaceTemp, x + (width * i), y));

			sdl_textureArray[i] = SDL_CreateTextureFromSurface(window->sdl_renderer, sdl_surfaceArray[i]);
		}
		// 
		SDL_FreeSurface(sdl_surfaceTemp);

		//
		sdl_textureCurrent = sdl_textureArray[0];
	}
	Sprite::Sprite(Window* _window, cstring _path, Vector2D _vector, float _angle)
		: window(_window), path(_path), vector(_vector), angle(_angle)
	{
		sdl_surfaceCurrent = IMG_Load(_path);
		if (!CheckSurfaceLoaded(sdl_surfaceCurrent))
			sdl_surfaceCurrent = SDL_CreateRGBSurface(SDL_SWSURFACE, 64, 64, 32, 0, 0, 0, 0);		

		sdl_textureCurrent = SDL_CreateTextureFromSurface(window->sdl_renderer, sdl_surfaceCurrent);
		width = sdl_surfaceCurrent->w;
		height = sdl_surfaceCurrent->h;
		isAnimated = false;
	}
	Sprite::Sprite(Window* _window, cstring _path, Vector2D _vector)
		: Sprite::Sprite(_window, _path, _vector, 0){}
	Sprite::Sprite(Window* _window, cstring _path) 
		: Sprite::Sprite(_window, _path, { 0, 0 }, 0) {}

	Sprite::~Sprite()
	{
		if (isAnimated)
		{
			for (uint32 i = 0; i < frameAmount; i++)
			{
				SDL_FreeSurface(sdl_surfaceArray[i]);
				SDL_DestroyTexture(sdl_textureArray[i]);
			}
		}

		SDL_FreeSurface(sdl_surfaceCurrent);
		SDL_DestroyTexture(sdl_textureCurrent);
	}

	bool Sprite::CheckSurfaceLoaded(SDL_Surface* _sdl_surface)
	{
		if (!_sdl_surface)
		{
			g_error_occurred = true;
			Console::WriteError();
			Console::Write(SDL_GetError());
			Console::WriteLine();
			return false;
		}
		return true;
	}

	uint32 Sprite::GetPixel(SDL_Surface* surface, uint32 x, uint32 y)
	{
		int bpp = surface->format->BytesPerPixel;
		uint8* p = (uint8*)surface->pixels + y * (uint32)surface->pitch + x * (int32)bpp;
		return p[0] << 24 | p[1] << 16 | p[2] << 8 | p[3] << 0;
		//uint32* pixels = (uint32*)surface->pixels;
		//return pixels[(y * surface->w) + x];
	}
	void Sprite::SetPixel(SDL_Surface* surface, uint32 x, uint32 y, uint32 pixel)
	{
		uint8* target_pixel = (uint8*)surface->pixels + y * surface->pitch + x * 4;
		*(uint32*)target_pixel = pixel;
	}
	void Sprite::NextFrame(uint32& frameIndex, float& frameTimer)
	{
		if (!isAnimated)
			return;

		if (frameTimer == 0)
			frameIndex++;

		if (frameIndex >= frameAmount)
		{
			frameIndex = 0;
			frameTimer = 0;
		}

		frameTimer += 1 * window->GetDeltaTime();
		if (frameTimer >= frameDelay)
			frameTimer = 0;
	}
	void Sprite::ResetFrame(uint32& frameIndex)
	{
		frameIndex = 0;
	}
	bool Sprite::CheckPixel(int x, int y, ubyte alpha)
	{
		return false;
	}
	bool Sprite::CheckPixel(int x, int y, ubyte red, ubyte green, ubyte blue)
	{
		return false;
	}
	bool Sprite::CheckPixel(int x, int y, ubyte red, ubyte green, ubyte blue, ubyte alpha)
	{
		return false;
	}

	uint32 Sprite::GetFrameAmount()
	{
		return frameAmount;
	}
}
