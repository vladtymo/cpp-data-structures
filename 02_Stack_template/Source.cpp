#include <iostream>
using namespace std;

template <typename T>
class Stack
{
private:
	T* items;
	int count;

public:
	Stack()
	{
		items = nullptr;
		count = 0;
	}
	~Stack() { Clear(); }

	void Push(T value)
	{
		T* newArray = new T[count + 1];

		for (size_t i = 0; i < count; i++)
			newArray[i] = items[i];

		newArray[count] = value;

		if (this->items != nullptr) delete[] this->items;
		this->items = newArray;

		++count;
	}
	T Pop()
	{
		if (IsEmpty()) return 0;

		// get last element
		T lastItem = Peek();

		if (count == 1)
		{
			Clear();
		}
		else
		{
			--count;
			T* newArray = new T[count];

			for (size_t i = 0; i < count; i++)
				newArray[i] = items[i];

			delete[] items;
			items = newArray;
		}

		return lastItem;
	}
	T Peek() const
	{
		if (IsEmpty()) return 0;
		return items[count - 1];
	}

	void Clear()
	{
		if (!IsEmpty())
		{
			delete[] items;
			items = nullptr;
			count = 0;
		}
	}

	bool IsEmpty() const
	{
		return count == 0;
	}
	int GetCount() const
	{
		return count;
	}
};

int main()
{
	Stack<string> colors;

	colors.Push("Red");
	colors.Push("White");
	colors.Push("Pink");
	colors.Push("Green");

	cout << "Last Color: " << colors.Peek() << endl;

	return 0;
}