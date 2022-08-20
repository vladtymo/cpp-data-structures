#include <iostream>
using namespace std;

struct Node
{
	int data;	// value to store
	Node* next;	// pointer to the next element
	Node* prev;	// pointer to the previous element
};

class DoubleLinkedList
{
private:
	Node* head;
	Node* tail;
public:
	DoubleLinkedList()
	{
		head = nullptr;
		tail = nullptr;
	}

	void AddHead(int value)
	{
		// create new node
		Node* newNode = new Node;
		newNode->data = value;
		newNode->next = head;
		newNode->prev = nullptr;

		if (IsEmpty())
		{
			// update tail
			head = newNode;
			tail = newNode;
		}
		else
		{
			// update links
			head->prev = newNode;
		}

		// update head
		head = newNode;
	}
	void DeleteHead()
	{
		if (IsEmpty()) return;

		// save next node pointer
		Node* next = head->next;

		// delete head
		delete head;

		// update head
		head = next;

		if (next != nullptr)
		{
			// clear links 
			next->prev = nullptr;
		}
		else
		{
			// clear tail
			tail = nullptr;
		}
	}

	void AddTail(int value)
	{
		if (IsEmpty())
		{
			AddHead(value);
			return;
		}

		// create new node
		Node* newNode = new Node;
		newNode->data = value;
		newNode->next = nullptr;
		newNode->prev = tail;

		// link new element
		tail->next = newNode;

		// update tail
		tail = newNode;
	}
	void DeleteTail()
	{
		if (IsEmpty()) return;

		// save previous node pointer
		Node* prev = tail->prev;

		// delete tail
		delete tail;

		// update tail
		tail = prev;

		if (prev != nullptr)
		{
			// clear links 
			prev->next = nullptr;
		}
		else
		{
			// clear head
			head = nullptr;
		}
	}

	bool IsEmpty() const
	{
		return head == nullptr;
	}

	void Show() const
	{
		if (IsEmpty())
		{
			cout << "List is empty.";
			return;
		}

		// using while cycle
		/*Node* iterator = head;
		while (iterator != nullptr)
		{
			cout << iterator->data << " ";
			iterator = iterator->next;
		}*/

		// using for cycle
		for (Node* i = head; i != nullptr; i = i->next)
		{
			cout << i->data << " ";
		}
		cout << endl;
	}
};

int main()
{
	DoubleLinkedList list;

	list.AddHead(555);
	list.AddHead(230);
	list.AddHead(135);
	list.AddHead(199);

	list.Show();

	list.AddTail(98);
	list.AddTail(120);
	list.AddTail(77);
	list.AddTail(5835);

	list.Show();

	while (!list.IsEmpty())
	{
		list.DeleteTail();
		list.Show();
	}

	return 0;
}