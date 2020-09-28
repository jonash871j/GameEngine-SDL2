#pragma once
#include "en_def.h"
#include "en_vector2d.h"

namespace Engine
{
	class Draw
	{
	private:
		int32 red = 0, green = 0, blue = 0, alpha = 255;

	private:
		Window* window;

	public:
		Draw(Window* window);
		~Draw();

	private:
		void SetColor();

	public:
		void Color(uint8 red, uint8 green, uint8 blue, uint8 alpha = 255);

	public:
		void Background();
		void Background(Engine::Sprite* sprite);

	public:
		void Point(int32 x, int32 y);
		void Point(Vector2D& a);

	public:
		void Line(int32 x1, int32 y1, int32 x2, int32 y2);
		void Line(Vector2D& a, Vector2D& b);

	public:
		void Triangle(int32 x1, int32 y1, int32 x2, int32 y2, int32 x3, int32 y3);
		void Triangle(Vector2D& a, Vector2D& b, Vector2D& c);

	public:
		void Rectangle(int32 x, int32 y, int32 width, int32 height, bool isFilled = false);
		void Rectangle(Vector2D& a, int32 width, int32 height, bool isFilled = false);

	public:
		void Text(Engine::Text* text, int32 x1, int32 y1, TextAlignment alignment = TextAlignment::Left);

	public:
		//void Object(Engine::Object* object, Vector2D offset = { 0, 0 });

	public:
		void Sprite(Engine::Sprite* sprite, Vector2D position = { 0, 0 });
	};
}
