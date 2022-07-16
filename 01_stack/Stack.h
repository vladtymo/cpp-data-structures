#pragma once

/*
	Стек - динамічна структура даних, що представляє із себе
	упорядкований набір елементів, в якій додавання нових
	елементів і видалення існуючих проводиться з одного кінця,
	званого вершиною стека.
	Діє принцип LIFO (Last In First Out) або «останній прийшов перший пішов»
*/

class Stack
{
private:
	// масив для зберігання даних
	int* items;
	// кількість клементів в масиві
	int count;

public:
	Stack()
	{
		items = nullptr;
		count = 0;
	}
	// Stack(collection)...

	~Stack() { Clear(); }

	void Push(int value);
	int Pop();
	int Peek() const;
	
	void Clear();

	bool IsEmpty() const
	{
		return count == 0;
	}
	int GetCount() const
	{
		return count;
	}
};

