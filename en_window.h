#pragma once
#include "en_def.h"

typedef struct SDL_Window SDL_Window;
typedef struct SDL_Renderer SDL_Renderer;

namespace Engine
{
	class Window
	{	
		friend class Draw;
		friend class Sprite;
	private:
		int32 width, height;
		int32 windowWidth, windowHeight;
		int32 pixelWidth, pixelHeight;

	private: 
		bool isConsoleVisible = true;
		bool isFullscreen = false;
		bool isClosed = false;

	private:
		float deltaTime = 0.0f;

	private:
		SDL_Window* sdl_window = nullptr;
		SDL_Renderer* sdl_renderer = nullptr;

	public:
		Window(int32 width, int32 height, cstring title, bool cappedFPS);
		~Window();

	public:
		bool Events();
		void Update();
		void Clear();

	public:
		void SetScaleing(uint8 xScale, uint8 yScale);
		void SetIsConsoleVisible(bool state);
		void SetIsFullscreen(bool state);
		void SetIsClosed(bool state);

	public:
		int32 GetWidth();
		int32 GetHeight();
		int32 GetWindowWidth();
		int32 GetWindowHeight();
		int32 GetPixelWidth();
		int32 GetPixelHeight();
		float GetDeltaTime();
		float GetFrameRate();
		bool GetIsConsoleVisible();
		bool GetIsFullscreen();
		bool GetIsClosed();
	};
}