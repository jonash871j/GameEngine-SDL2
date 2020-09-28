#include "en_engine.h"
#include "SDL_render.h"

namespace Engine
{
	Draw::Draw(Window* window)
		:window(window)
	{

	}

	Draw::~Draw(){}

	void Draw::Color(uint8 red, uint8 green, uint8 blue, uint8 alpha)
	{
		this->red = red;
		this->green = green;
		this->blue = blue;
		this->alpha = alpha;
	}

	void Draw::SetColor()
	{
		SDL_SetRenderDrawColor(window->sdl_renderer, red, green, blue, alpha);
	}
	void Draw::Background()
	{
		Rectangle(0, 0, window->width, window->height, true);
	}
	void Draw::Background(Engine::Sprite* sprite)
	{
		SDL_Rect rect = { 0, 0, window->width, window->height };
		SDL_RenderCopy(window->sdl_renderer, sprite->sdl_textureCurrent, NULL, &rect);
		//if (_sprite->isAnimated)
		//	_sprite->NextFrame();
	}

	void Draw::Point(int32 x, int32 y)
	{
		SetColor();
		SDL_RenderDrawPoint(window->sdl_renderer, x, y);
	}

	void Draw::Point(Vector2D& a)
	{
		Point(a.GetX(), a.GetY());
	}

	void Draw::Line(int32 x1, int32 y1, int32 x2, int32 y2)
	{
		SetColor();
		SDL_RenderDrawLine(window->sdl_renderer, x1, y1, x2, y2);
	}

	void Draw::Line(Vector2D& a, Vector2D& b)
	{
		Line(a.GetX(), a.GetY(), b.GetX(), b.GetY());
	}

	void Draw::Triangle(int32 x1, int32 y1, int32 x2, int32 y2, int32 x3, int32 y3)
	{
		SetColor();
		SDL_RenderDrawLine(window->sdl_renderer, x1, y1, x2, y2);
		SDL_RenderDrawLine(window->sdl_renderer, x2, y2, x3, y3);
		SDL_RenderDrawLine(window->sdl_renderer, x3, y3, x1, y1);
	}

	void Draw::Triangle(Vector2D& a, Vector2D& b, Vector2D& c)
	{
		Triangle(a.GetX(), a.GetY(), b.GetX(), b.GetY(), c.GetX(), c.GetY());
	}

	void Draw::Rectangle(int32 x, int32 y, int32 width, int32 height, bool isFilled)
	{
		SetColor();
		SDL_Rect rect = { x, y, width, height };
		
		if (!isFilled)
			SDL_RenderDrawRect(window->sdl_renderer, &rect);
		else
			SDL_RenderFillRect(window->sdl_renderer, &rect);
	}

	void Draw::Rectangle(Vector2D& a, int32 width, int32 height, bool isFilled)
	{
		Rectangle(a.GetX(), a.GetY(), width, height, isFilled);
	}

	void Draw::Text(Engine::Text* text, int32 x1, int32 y1, TextAlignment alignment)
	{
		SDL_Rect rect = { x1, y1, 0, 0 };

		if (alignment == TextAlignment::Centered)
			rect = { x1 - ((text->size * text->font->size) / 2), y1, 0, 0 };

		if (alignment == TextAlignment::Right)
			rect = { x1 - (text->size * text->font->size), y1, 0, 0 };

		SDL_DestroyTexture(text->sdl_texture);
		text->sdl_texture = SDL_CreateTextureFromSurface(window->sdl_renderer, text->sdl_surface);
		SDL_QueryTexture(text->sdl_texture, NULL, NULL, &rect.w, &rect.h);
		SDL_RenderCopy(window->sdl_renderer, text->sdl_texture, NULL, &rect);
	}

	//void Draw::Sprite(Engine::Sprite* _sprite)
	//{
	//	SDL_Rect rect = { _sprite->vector.x, _sprite->vector.y, _sprite->width, _sprite->height };
	//	SDL_RenderCopyEx(window->sdl_renderer, _sprite->sdl_textureCurrent, NULL, &rect, _sprite->angle, 0, SDL_FLIP_NONE);
	//	if (_sprite->isAnimated)
	//		_sprite->NextFrame();
	//}
	//void Draw::Object(Engine::Object* object, Vector2D offset)
	//{
	//	SDL_Rect rect = { 
	//		(int32)(object->vector.x + ((object->width - object->sprite->width) / 2) + offset.x), 
	//		(int32)(object->vector.y + ((object->height - object->sprite->height) / 2) + offset.y), 
	//		object->sprite->width,
	//		object->sprite->height 
	//	};

	//	SDL_RenderCopyEx(window->sdl_renderer, object->sprite->sdl_textureCurrent, NULL, &rect, object->sprite->angle, 0, SDL_FLIP_NONE);	
	//}
	void Draw::Sprite(Engine::Sprite* sprite, Vector2D position)
	{
		SDL_Rect rect = { (int32)(sprite->Vector.x + position.x), (int32)(sprite->Vector.y + position.y), sprite->width, sprite->height };
		SDL_RenderCopyEx(window->sdl_renderer, sprite->sdl_textureCurrent, NULL, &rect, sprite->angle, 0, SDL_FLIP_NONE);
	}
}