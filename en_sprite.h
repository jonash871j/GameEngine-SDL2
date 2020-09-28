#pragma once
#include "en_def.h"
#include "en_vector2d.h"

namespace Engine
{
	class Sprite
	{	
		friend class Draw;
		friend class Object;
	private:
		int32 width, height;
		float angle;
		Vector2D vector;
		cstring path;

	private:
		bool isAnimated = false;
		float frameDelay = 0.0f;
		uint32 frameAmount = 0;

	private:
		SDL_Surface** sdl_surfaceArray = nullptr;
		SDL_Texture** sdl_textureArray = nullptr;

	private:
		SDL_Surface* sdl_surfaceCurrent = nullptr;
		SDL_Texture* sdl_textureCurrent = nullptr;
	
	private:
		Window* window;

	public: // Sprite animation frames
		Sprite(Window* _window, cstring _path, Vector2D _vector, float _angle, uint32 _frameWidth, uint32 _frameDelay);

	public: // Sprite static frame
		Sprite(Window* _window, cstring _path, Vector2D _vector, float _angle);
		Sprite(Window* _window, cstring _path, Vector2D _vector);
		Sprite(Window* _window, cstring _path);

	public:
		~Sprite();

	private:
		bool CheckSurfaceLoaded(SDL_Surface* _sdl_surface);

	private:
		uint32 GetPixel(SDL_Surface* surface, uint32 x, uint32 y);
		void SetPixel(SDL_Surface* surface, uint32 x, uint32 y, uint pixel);

	public:
		void NextFrame(uint32& frameIndex, float& frameTimer);
		void ResetFrame(uint32& frameIndex);

	public:
		bool CheckPixel(int x, int y, ubyte alpha);
		bool CheckPixel(int x, int y, ubyte red, ubyte green, ubyte blue);
		bool CheckPixel(int x, int y, ubyte red, ubyte green, ubyte blue, ubyte alpha);

	public:
		uint32 GetFrameAmount();
			 
	public: 
#pragma region Properties
		_property(uint32, Width); 
			_get(Width) { return width; }
		_property(uint32, Height); 
			_get(Height) { return height; }
		
		_property(float, Angle);
			_get(Angle) { return angle; } 
			_set(Angle) { if (value < 0.0f) angle = 359.99f; else if (angle > 359.99f) angle = 0; else angle = value; }
		
		_property(Vector2D, Vector); 
			_get(Vector) { return vector; } 
			_set(Vector) { vector = value; }

		_property(Vector2D*, VectorPointer);
			_get(VectorPointer) { return &vector; }

		_property(Vector2D, VectorCentrum);
			_get(VectorCentrum) { Vector2D vectorCentrum = vector; vectorCentrum.x = vector.x + width / 2; vectorCentrum.y = vector.y + height / 2; return vectorCentrum; }
#pragma endregion
	
	};
}
