#include "en_window.h"

#include "en_console.h"
#include "en_input.h"
#include "en_misc.h"

#include "SDL_video.h"
#include "SDL_render.h"
#include "SDL_events.h"
#include "SDL_image.h"
#include "SDL_ttf.h"

#include <chrono>
#include <time.h> 
#include <Windows.h>

namespace Engine
{
	static SDL_Event sdl_event;
	static auto tp1 = std::chrono::system_clock::now();
	static auto tp2 = std::chrono::system_clock::now();

	Window::Window(int32 width, int32 height, cstring title, bool cappedFPS)
		: width(width), height(height)
	{
		// Initialize SDL engine and other components 
		SDL_Init(0x00000020u);
		IMG_Init(IMG_INIT_PNG);
		TTF_Init();

		// Initialize SDL window
		sdl_window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, NULL);

		Console::WriteErrorLine("Could't initialize SDL window", sdl_window);

		// Initialize SDL renderer
		if (cappedFPS)
			sdl_renderer = SDL_CreateRenderer(sdl_window, -1, SDL_RENDERER_PRESENTVSYNC);
		else
			sdl_renderer = SDL_CreateRenderer(sdl_window, -1, SDL_RENDERER_ACCELERATED);

		Console::WriteErrorLine("Could't initialize SDL renderer", sdl_window);

		// Set SDL rendermode
		SDL_SetRenderDrawBlendMode(sdl_renderer, SDL_BLENDMODE_BLEND);

		// Sets scaleing
		SetScaleing(1, 1);

		// Set seed
		Misc::Seed((uint32)time(NULL));

		Console::WriteLine("Window has been initialized");
	}

	Window::~Window()
	{
		if (sdl_renderer)
		SDL_DestroyRenderer(sdl_renderer);

		if (sdl_window)
			SDL_DestroyWindow(sdl_window);

		SDL_Quit();
		Console::WriteLine("Window has been destroyed");
	}

	bool Window::Events()
	{
		// Sdl events
		SDL_Event sdl_event;

		if (SDL_PollEvent(&sdl_event))
		{
			switch (sdl_event.type)
			{
			case SDL_QUIT:
				isClosed = true;
				break;
			}
		}

		// Input
		Input::Update();

		// Mouse
		int32 mouseX = int32((float)Input::MouseX());
		int32 mouseY = int32((float)Input::MouseY());
		if ((mouseX >= 0) && (mouseX < windowWidth) && (mouseY >= 0) && (mouseY < windowHeight))
			SDL_ShowCursor(false);
		else
			SDL_ShowCursor(true);

		// Delta time
		tp2 = std::chrono::system_clock::now();
		std::chrono::duration<float> elapsedTime = tp2 - tp1;
		tp1 = tp2;
		deltaTime = elapsedTime.count() * 100.0f;

		return isClosed;
	}

	void Window::Update()
	{
		SDL_RenderPresent(sdl_renderer);
	}
	void Window::Clear()
	{
		SDL_RenderClear(sdl_renderer);
	}
	void Window::SetScaleing(uint8 pixelWidth, uint8 pixelHeight)
	{
		this->pixelWidth = pixelWidth;
		this->pixelHeight = pixelHeight;

		SDL_RenderSetLogicalSize(sdl_renderer, width, height);
		SDL_SetWindowSize(sdl_window, width * pixelWidth, height * pixelHeight);
	}
	void Window::SetIsConsoleVisible(bool state)
	{
		isConsoleVisible = state;

		if (isConsoleVisible)
			ShowWindow(GetConsoleWindow(), SW_RESTORE);
		else
			ShowWindow(GetConsoleWindow(), SW_HIDE);
	}
	void Window::SetIsFullscreen(bool state)
	{
		isFullscreen = state;

		if (isFullscreen)
		{
			Clear();
			SDL_SetWindowFullscreen(sdl_window, SDL_WINDOW_FULLSCREEN_DESKTOP);
			SDL_SetRelativeMouseMode(SDL_TRUE);
		}
		else
		{
			Clear();
			SDL_SetWindowFullscreen(sdl_window, SDL_WINDOW_FOREIGN);
			SDL_SetRelativeMouseMode(SDL_FALSE);
		}
	}
	void Window::SetIsClosed(bool state)
	{
		this->isClosed = state;
	}

	int32 Window::GetWidth()
	{
		return width;
	}
	int32 Window::GetHeight()
	{
		return height;
	}
	int32 Window::GetWindowWidth()
	{
		SDL_GetWindowSize(sdl_window, &windowWidth, &windowHeight);
		return windowWidth;
	}
	int32 Window::GetWindowHeight()
	{
		SDL_GetWindowSize(sdl_window, &windowWidth, &windowHeight);
		return windowHeight;
	}
	int32 Window::GetPixelWidth()
	{
		return pixelWidth;
	}
	int32 Window::GetPixelHeight()
	{
		return pixelHeight;
	}
	float Window::GetDeltaTime()
	{
		return deltaTime;
	}
	float Window::GetFrameRate()
	{
		return 100.0f * (1.0f / deltaTime);
	}
	bool Window::GetIsConsoleVisible()
	{
		return false;
	}
	bool Window::GetIsClosed()
	{
		return isClosed;
	}
	bool Window::GetIsFullscreen()
	{
		return isFullscreen;
	}
}