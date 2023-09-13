#include <iostream>

using namespace std;

class List
{
public:
	List();
	void Add_begin(int data);
	void Add_end(int data);
	void Search_el();
	void Display();
	~List();

private:
	class Node
	{
	public:
		Node* pNext;
		int data;
		Node(int data = NULL, Node* pNext = nullptr)
		{
			this->data = data;
			this->pNext = pNext;
		}
	};
	int Size;
	Node* head = new Node();
};

List::List()//initializations.
{
	Size = 0;
	head = nullptr;
}

List::~List()//Destructor.
{
	Node* temp = head;
	while (Size != NULL)
	{
		head = head->pNext;
		delete temp;
		Size--;
	}
}

void List::Add_begin(int data)//Add element to begin.
{
	head = new Node(data, head);
	Size++;
}

void List::Add_end(int data)//Add element to beck.
{
	if (head == nullptr)
	{
		return Add_begin(data);
	}
	else
	{
		Node* lst = this->head;
		while (lst->pNext != nullptr)
		{
			lst = lst->pNext;
		}
		lst->pNext = new Node(data);
	}
	Size++;
}

void List::Search_el()//Search element.
{
	Node* temp = head;
	cout << temp->data << " ";
}

void List::Display()
{
	Node* temp = head;
	while (temp != nullptr)
	{
		cout << temp->data << " ";
		temp = temp->pNext;
	}
	cout << endl;
}

int main()
{
	List lst;

	lst.Add_begin(3);
	lst.Add_begin(6);
	lst.Add_begin(9);
	lst.Display();
	lst.Search_el();
}