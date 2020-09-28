//#include "en_object.h"
//
//#include "en_sprite.h"
//#include "en_console.h"
//#include "en_window.h"
//
//#include <math.h>
//#include <iostream>
//
//namespace Engine
//{
//	Object::Object(Engine::Sprite* sprite)
//		: Object(sprite, sprite->width, sprite->height, { 0, 0 }) 
//	{
//	}
//	Object::Object(Engine::Sprite* sprite, Vector2D vector)
//		: Object(sprite, sprite->width, sprite->height, vector)
//	{
//	}
//	Object::Object(Engine::Sprite* sprite, int32 width, int32 height)
//		: Object(sprite, width, height, { 0, 0 })
//	{
//	}
//	Object::Object(Engine::Sprite* sprite, int32 width, int32 height, Vector2D vector)
//		: sprite(sprite), width(width), height(height), vector(vector), vectorTest(vector)
//	{
//	}
//	Object::~Object(){}
//
//	//bool Object::LineCollide(Object* object, Vector2D offset)
//	//{
//	//	if ((vector.x + offset.x >= object->vector.x) && (vector.x + offset.x < object->vector.x + width) &&
//	//		((vector.y + (height / 2)) + offset.y >= object->vector.y) && ((vector.y + (height) / 2)) + offset.y < object->vector.y + object->height)
//	//		return true;
//	//	return false;
//	//}
//	bool Object::BoxCollide(Object* object, Vector2D offset)
//	{
//		float x1 = vectorTest.x + offset.x;
//		float y1 = vectorTest.y + offset.y;
//		float x2 = object->vectorTest.x;
//		float y2 = object->vectorTest.y;
//
//		float xoVec = object->vectorTest.x;
//		float yoVec = object->vectorTest.y;
//		float oWidth = object->width;
//		float oHeight = object->height;
//
//		if (((x1 + width >= xoVec) && (x1 < xoVec + oWidth)) && ((y1 + height >= yoVec) && (y1 < yoVec + oHeight)))
//		{
//			vectorTest = vector;
//			return true;
//		}
//		else
//		{
//			vector = vectorTest;
//			return false;
//		}
//	}
//	//bool Object::BoxInsideCollide(Object* object, Vector2D offset)
//	//{
//	//	float x1 = vector.x + offset.x;
//	//	float y1 = vector.y + offset.y;
//	//	float x2 = object->vector.x;
//	//	float y2 = object->vector.y;
//
//	//	float xoVec = object->vector.x;
//	//	float yoVec = object->vector.y;
//	//	float oWidth = object->width;
//	//	float oHeight = object->height;
//
//	//	// BUG: inconsistent
//	//	if (((x1 >= xoVec) && (x1 + width < xoVec + oWidth)) &&
//	//		((y1 >= yoVec) && (y1 + height < yoVec + oHeight)))
//	//		return false;
//	//	return true;
//	//}
//
//	bool Object::BoxPhysicCollide(Object* object, Vector2D offset)
//	{
//		float x1 = vectorTest.x + offset.x;
//		float y1 = vectorTest.y + offset.y;
//		float x2 = object->vectorTest.x;
//		float y2 = object->vectorTest.y;
//
//		float xoVec = object->vectorTest.x;
//		float yoVec = object->vectorTest.y;
//		float oWidth = object->width;
//		float oHeight = object->height;
//
//		if (((x1 + width >= xoVec) && (x1 < xoVec + oWidth)) && ((y1 + height >= yoVec) && (y1 < yoVec + oHeight)))
//		{
//			const Vector2D& delta = GetVectorDelta();
//			object->vector += delta;
//			object->isCollied = true;
//			return true;
//		}
//		else
//		{
//			return false;
//		}
//	}
//
//	bool Object::WindowCollide(Window* window)
//	{
//		if ((vectorTest.x < 0) || (vectorTest.x + width-1 > window->GetWidth()) || (vectorTest.y < 0) || (vectorTest.y + height-1 > window->GetHeight()))
//		{
//			isCollied = true;
//			return true;
//		}
//		else
//		{
//			return false;
//		}
//	}
//
//	float Object::DistanceToObject(Object* object)
//	{
//		const Vector2D& thisCenter = GetVectorCenter();
//		const Vector2D& objCenter = object->GetVectorCenter();
//		return sqrtf(powf((objCenter.y - thisCenter.y), 2) + powf((objCenter.x - thisCenter.x), 2));
//	}
//
//	const Vector2D Object::DeltaToObject(Object* object)
//	{
//		return Vector2D(object->vectorTest.x - vectorTest.x, object->vectorTest.y - vectorTest.y);
//	}
//
//	Sprite* Object::GetSprite()
//	{
//		return sprite;
//	}
//	Vector2D& Object::GetVector()
//	{
//		return vectorTest;
//	}
//
//	const Vector2D Object::GetVectorCenter()
//	{
//		return Vector2D(vectorTest.x + (width / 2), vectorTest.y + (height / 2));
//	}
//
//	const Vector2D Object::GetVectorDelta()
//	{
//		return Vector2D(vectorTest.x - vector.x, vectorTest.y - vector.y);
//	}
//
//
//	void Object::SetSprite(Engine::Sprite* sprite)
//	{
//		this->sprite = sprite;
//	}
//
//	void Object::SetVector(Vector2D vector)
//	{
//		this->vector = vector;
//	}
//	void Object::UpdateVector()
//	{
//		if (!isCollied)
//			vector = vectorTest;
//		else
//			vectorTest = vector;
//		isCollied = false;
//	}
//}
