#pragma once
#define _property(t,n)  __declspec( property  \
(put = _Set##n, get = _Get##n)) t n; \
	typedef t tmp_type_##n

#define _get(n) tmp_type_##n _Get##n() 
#define _set(n) void _Set##n(const tmp_type_##n& value)    

typedef struct SDL_Surface SDL_Surface;
typedef struct SDL_Texture SDL_Texture;
typedef struct SDL_Color SDL_Color;

namespace Engine
{
	typedef unsigned __int64 uint64;
	typedef unsigned __int32 uint32;
	typedef unsigned __int16 uint16;
	typedef unsigned __int8 uint8;

	typedef signed __int64 int64;
	typedef signed __int32 int32;
	typedef signed __int16 int16;
	typedef signed __int8 int8;

	typedef unsigned char ubyte;
	typedef signed char sbyte;
	typedef unsigned short ushort;
	typedef signed short sshort;
	typedef unsigned int uint;
	typedef signed int sint;

	typedef class Window Window;
	typedef class Sprite Sprite;
	typedef class Object Object;
	typedef class Draw Draw;
	typedef class Font Font;
	typedef class Text Text;

	typedef const char* cstring;

	enum class TextAlignment
	{
		Left,
		Centered,
		Right,
	};

	inline bool g_error_occurred = false;

	namespace Core
	{
		void Delay(uint duration);
	}
	namespace EncapsulationClasses
	{
		typedef struct E_TTF_Font E_TTF_Font;
		typedef struct E_Thread E_Thread;
	}
}