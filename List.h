#pragma once

template <typename T>
struct Cell
{
	Cell<T>* prev = nullptr;
	Cell<T>* next = nullptr;
	T data;
};

template <typename T>
class List
{
	~List()
	{
		Clear(); // ƒƒ‚ƒŠƒŠ[ƒN‚Íß
	};

private:
	Cell<T>* dummy;
	
private:
	void PushBack(T obj)
	{

	}

	void Insert(Cell<T> itr, T obj)
	{

	}

	void Erase(Cell<T> itr)
	{
	
	}

	void Clear()
	{
		
	}

	Cell<T>* GetBegin()
	{
		return &dummy->next;
	}

	Cell<T>* GetEnd()
	{
		return &dummy->prev;
	}

	T* GetFront()
	{
		return &dummy->next->data;
	}

	T* GetBack()
	{
		return &dummy->prev->data;
	}

	T* GetData(unsigned int index)
	{
		Cell<T>* current = GetBegin();

		for (int i = 0; i < index; i++)
		{
			current = current->next;
		}

		return &current->data;
	}
};

