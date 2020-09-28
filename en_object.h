//#pragma once
//#include "en_def.h"
//#include "en_vector2d.h"
//#include "en_sprite.h"
//
//namespace Engine
//{
//	class Object
//	{	
//		friend class Draw;
//	private:
//		bool isCollied = false;
//
//	protected:
//		Sprite* sprite;
//		Vector2D vector = { 0, 0 };
//		Vector2D vectorTest = { 0, 0 };
//
//	protected:
//		uint32 width;
//		uint32 height;
//
//	public:
//		Object(Sprite* sprite);
//		Object(Sprite* sprite, Vector2D vector);
//		Object(Sprite* sprite, int32 width, int32 height);
//		Object(Sprite* sprite, int32 width, int32 height, Vector2D vector);
//		~Object();
//
//	public:
//		void UpdateVector();
//
//	public:
//		//bool LineCollide(Object* object, Vector2D offset);
//		bool BoxCollide(Object* object, Vector2D offset);
//		//bool BoxInsideCollide(Object* object, Vector2D offset);
//		bool BoxPhysicCollide(Object* object, Vector2D offset);
//
//		bool WindowCollide(Window* window);
//
//	public:
//		float DistanceToObject(Object* object);
//		const Vector2D DeltaToObject(Object* object);
//
//	public:
//		Sprite* GetSprite();
//		Vector2D& GetVector();
//		const Vector2D GetVectorCenter();
//		const Vector2D GetVectorDelta();
//
//	public:
//		void SetSprite(Sprite* sprite);
//		void SetVector(Vector2D vector);
//
//	public:
//		__declspec(property(get = GetVector, put = SetVector)) Vector2D& Vector;
//		__declspec(property(get = GetSprite, put = SetSprite)) Sprite* Sprite;
//	};
//}
//
