#pragma once
#include "en_def.h"

namespace Engine
{
	template<class T>
	class List
	{
	private:
		T** items = nullptr;
		uint32 length = 0;

	public:
		List();
		~List();

	public:
		void Add(T* item);
		void Remove();
		void RemoveAt(uint32 index);
		void Clear();

	public:
		uint32 GetLength();

	public:
		T* operator[](uint32 index);
	};

	template<class T>
	inline List<T>::List()
	{
	}
	template<class T>
	inline List<T>::~List()
	{
	}

	template<class T>
	inline void List<T>::Add(T* item)
	{
		if (length == 0)
		{	
			length++;
			items = new T*[length];
			items[length - 1] = item;
		}
		else
		{
			//length++;
			//T** itemsSave = new T*[length];
			//goto CREATE;
		}
	}
	template<class T>
	inline void List<T>::Remove()
	{
	}
	template<class T>
	inline void List<T>::RemoveAt(uint32 index)
	{
	}
	template<class T>
	inline void List<T>::Clear()
	{
	}
	template<class T>
	inline uint32 List<T>::GetLength()
	{
		return length;
	}
	template<class T>
	inline T* List<T>::operator[](uint32 index)
	{
		return items[index];
	}
}