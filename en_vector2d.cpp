#include "en_vector2d.h"

#include <math.h>

namespace Engine
{
	Vector2D::Vector2D() 
		: x(0), y(0)
	{

	}
	Vector2D::Vector2D(float x, float y) 
		: x(x), y(y)
	{

	}
	Vector2D::Vector2D(int32 x, int32 y)
		: x((float)x), y((float)y)
	{

	}

	Vector2D::Vector2D(const Vector2D& v) : x(v.x), y(v.y){}

	int32 Vector2D::GetX()
	{
		return (int32)x;
	}

	int32 Vector2D::GetY()
	{
		return (int32)y;
	}

	float Vector2D::mag()
	{
		return sqrtf(x * x + y * y); 
	}
	Vector2D Vector2D::norm()
	{ 
		float r = 1 / mag(); 
		return Vector2D(x * r, y * r); 
	}
	Vector2D Vector2D::perp() 
	{
		return Vector2D(-y, x); 
	}
	float Vector2D::dot(const Vector2D& rhs)
	{
		return this->x * rhs.x + this->y * rhs.y; 
	}
	float Vector2D::cross(const Vector2D& rhs)
	{ 
		return this->x * rhs.y - this->y * rhs.x; 
	}

	Vector2D Vector2D::operator +  (const Vector2D& rhs) 
	{ 
		return Vector2D(this->x + rhs.x, this->y + rhs.y); 
	}
	Vector2D Vector2D::operator -  (const Vector2D& rhs) 
	{
		return Vector2D(this->x - rhs.x, this->y - rhs.y); 
	}
	Vector2D Vector2D::operator *  (const float& rhs)
	{
		return Vector2D(this->x * rhs, this->y * rhs); 
	}
	Vector2D Vector2D::operator /  (const float& rhs)
	{
		return Vector2D(this->x / rhs, this->y / rhs); 
	}
	Vector2D& Vector2D::operator += (const Vector2D& rhs) 
	{
		this->x += rhs.x; this->y += rhs.y; return *this; 
	}
	Vector2D& Vector2D::operator -= (const Vector2D& rhs) 
	{
		this->x -= rhs.x; this->y -= rhs.y; return *this; 
	}
	Vector2D& Vector2D::operator *= (const float& rhs)
	{
		this->x *= rhs; this->y *= rhs; return *this; 
	}
	Vector2D& Vector2D::operator /= (const float& rhs)
	{
		this->x /= rhs; this->y /= rhs; return *this; 
	}
	float& Vector2D::operator [] (unsigned int i)
	{
		return *((float*)this + i);	   /* <-- D'oh :( */ 
	}
}