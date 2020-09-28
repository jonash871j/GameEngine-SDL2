#pragma once
#include "en_def.h"

namespace Engine
{
	struct Vector2D
	{
	public:
		float x, y;

	public:
		Vector2D();
		Vector2D(float x, float y);
		Vector2D(int32 x, int32 y);
		Vector2D(const Vector2D& v);

	public:
		int32 GetX();
		int32 GetY();

	public:
		float mag();
		Vector2D  norm();
		Vector2D  perp();
		float dot(const Vector2D& rhs);
		float cross(const Vector2D& rhs);

	public:
		Vector2D  operator +  (const Vector2D& rhs);
		Vector2D  operator -  (const Vector2D& rhs);
		Vector2D  operator *  (const float& rhs);
		Vector2D  operator /  (const float& rhs);
		Vector2D& operator += (const Vector2D& rhs);
		Vector2D& operator -= (const Vector2D& rhs);
		Vector2D& operator *= (const float& rhs);
		Vector2D& operator /= (const float& rhs);
		float& operator [] (unsigned int i);

	};
}
