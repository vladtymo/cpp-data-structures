#include "Stack.h"
#include <iostream>
using namespace std;

int main()
{
	Stack myStack;

	myStack.Push(5);
	myStack.Push(7);
	myStack.Push(10);
	myStack.Push(20);

	cout << "Last item: " << myStack.Peek() << endl;

	while (!myStack.IsEmpty())
	{
		cout << "Element: " << myStack.Pop() << endl;
	}

	cout << "Element: " << myStack.Pop() << endl;

	for (size_t i = 0; i < 10; i++)
	{
		myStack.Push(rand() % 100);
	}

	cout << "Count of elements: " << myStack.GetCount() << endl;
	myStack.Clear();
	cout << "Count of elements: " << myStack.GetCount() << endl;

	return 0;
}