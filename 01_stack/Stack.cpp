#include "Stack.h"

void Stack::Push(int value)
{
	int* newArray = new int[count + 1];
	
	for (size_t i = 0; i < count; i++)
		newArray[i] = items[i];

	newArray[count] = value;

	if (this->items != nullptr) delete[] this->items;
	this->items = newArray;

	++count;
}

int Stack::Pop()
{
	if (IsEmpty()) return 0;

	// get last element
	int lastItem = Peek();

	if (count == 1)
	{
		Clear();
	}
	else
	{
		--count;	
		int* newArray = new int[count];

		for (size_t i = 0; i < count; i++)
			newArray[i] = items[i];

		delete[] items;
		items = newArray;
	}

	return lastItem;
}

int Stack::Peek() const
{
	if (IsEmpty()) return 0;
	return items[count - 1];
}

void Stack::Clear()
{
	if (!IsEmpty())
	{
		delete[] items;
		items = nullptr;
		count = 0;
	}
}