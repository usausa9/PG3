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
public:
	List()
	{
		dummy = new Cell<T>;
	};

	~List()
	{
		Clear();		// ���������[�N�͍�
		delete dummy;	// ���������[�N�͍� season2
	};

	Cell<T>* dummy;
	
public:
	// �v�b�V���o�b�N����
	void PushBack(T obj)
	{
		Cell<T>* pBack;
		pBack = new Cell<T>();
		pBack->data = obj;
		pBack->prev = dummy->prev;
		pBack->next = nullptr;

		dummy->prev = pBack;

		if (pBack->prev)
		{
			pBack->prev->next = pBack;	// x + 1 - 1 = x��null�Ȃ̂ŋ����Ă�����
		}
		else
		{
			dummy->next = pBack;
		}
		
	}

	// �}������
	void Insert(Cell<T>* itr, T obj)
	{
		Cell<T>* iCell = nullptr;
		iCell = itr;

		if (iCell == nullptr) 
		{
			return PushBack(obj);
		}

		Cell<T>* newCell = new Cell<T>();
		newCell->data = obj;
		
		newCell->prev = iCell->prev;

		if (newCell->prev == nullptr)
		{
			dummy->next = newCell;
		}
		else
		{
			newCell->prev->next = newCell;
		}

		iCell->prev = newCell;
		newCell->next = iCell;
	}

	// �f�[�^���폜
	void Erase(Cell<T>* itr)
	{
		Cell<T>* delCell;
		delCell = itr;

		if (delCell->next) 
		{
			delCell->next->prev = delCell->prev;
		}
		else
		{
			dummy->prev = delCell->prev;
		}

		if (delCell->prev)
		{
			delCell->prev->next = delCell->next;
		}
		else
		{
			dummy->next = delCell->next;
		}

		delete delCell;
	}

	// �f�[�^��S�폜
	void Clear()
	{
		while (dummy->next)
		{
			Erase(dummy->next);
		}
	}

	// 1�ڂ̃Z�����擾
	Cell<T>* GetBegin()
	{
		return dummy->next;
	}

	// �Ō�̃Z�����擾
	Cell<T>* GetEnd()
	{
		return dummy->prev;
	}

	// index�Ԗڂ̃Z�����擾
	Cell<T>* GetCell(unsigned int index)
	{
		Cell<T>* current = GetBegin();

		for (int i = 0; i < index; i++)
		{
			if (current)
			{
				current = current->next;
			}
			else
			{
				return nullptr;
			}
		}

		return current;
	}

	// 1�ڂ̃Z���̃f�[�^���擾
	T* GetFront()
	{
		return &dummy->next->data;
	}

	// �Ō�̃Z���̃f�[�^���擾
	T* GetBack()
	{
		return &dummy->prev->data;
	}

	// index�Ԗڂ̃f�[�^���擾
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