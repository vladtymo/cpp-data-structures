#include <iostream>
using namespace std;

struct Node
{
	int data;	// value to store
	Node* next;	// pointer to the next element
};

class SingleLinkedList
{
private:
	Node* head;
public:
	SingleLinkedList()
	{
		head = nullptr;
	}

	void AddHead(int value)
	{
		// create new node
		Node* newNode = new Node;
		newNode->data = value;
		newNode->next = head;

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
	SingleLinkedList list;

	list.AddHead(555);
	list.AddHead(230);
	list.AddHead(135);
	list.AddHead(199);

	list.Show();

	while (!list.IsEmpty())
	{
		list.DeleteHead();
		list.Show();
	}

	return 0;
}