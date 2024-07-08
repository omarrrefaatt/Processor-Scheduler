#ifndef _LINKEDLIST
#define _LINKEDLIST

#include "Node.h"
#include <iostream>
using namespace std;

template <typename T>
class LinkedList
{
private:
	Node<T>* Head;	//Pointer to the head of the list
public:


	LinkedList()
	{
		Head = nullptr;
	}

	//List is being desturcted ==> delete all items in the list
	~LinkedList()
	{
		DeleteAll();
	}
	////////////////////////////////////////////////////////////////////////
	/*
	* Function: PrintList.
	* prints the items of all nodes in a linked list.
	*/
	bool isempty() {
		if (Head == nullptr) {
			return true;

		}
		return false;
	}
	void PrintList()	const
	{
		Node<T>* p = Head;

		while (p)
		{
			cout << *p->getItem();
			p = p->getNext();
		}
	}
	////////////////////////////////////////////////////////////////////////

	// Function: InsertBeg.
	// Creates a new node and adds it to the beginning of a linked list.
	void InsertBeg(const T& data)

	{
		Node<T>* R = new Node<T>(data);
		R->setNext(Head);
		Head = R;

	}
	///////////////////////////////////////////////////////////////////
	void DeleteAll()
	{
		Node<T>* P = Head;
		while (Head)
		{
			P = Head->getNext();
			delete Head;
			Head = P;
		}
	}


	//inserts a new node at end of the list
	void InsertEnd(const T& data)
	{
		if (Head == nullptr)
		{
			Node<T>* N = new Node<T>(data);
			Head = N;
		}
		else
		{
			Node<T>* p = Head;
			while (p->getNext() != nullptr)
			{
				p = p->getNext();
			}
			Node<T>* N = new Node<T>(data);
			p->setNext(N);
			N->setNext(nullptr);
		}

	}


	//Removes the first node from the list and returns it
	T DeleteFirst()
	{
		if (Head != nullptr)
		{
			T temp = Head->getItem();
			if (Head->getNext() != nullptr)
			{
				Node<T>* p = Head->getNext();
				delete Head;
				Head = p;
			}
			else
			{
				delete Head;
				Head = nullptr;
			}
			return temp;
		}
		return nullptr;
	}



	//deletes the first node with the given value (if found) and returns true
	//if not found, returns false
	bool DeleteNode(const T& value)
	{
		if (Head == nullptr) {
			// linked list is empty
			return false;
		}

		Node<T>* p = Head;
		if (p->getItem() == value)
		{
			// delete the first node
			if (p->getNext() == nullptr)
			{
				// list contains only one node
				delete p;
				Head = nullptr;
			}
			else
			{
				// list contains more than one node
				p = p->getNext();
				delete Head;
				Head = p;
			}
			return true;
		}

		// search for the node to delete
		while (p->getNext() != nullptr)
		{
			if (p->getNext()->getItem() == value)
			{
				// delete the node
				Node<T>* t = p->getNext();
				p->setNext(p->getNext()->getNext());
				delete t;
				return true;
			}
			p = p->getNext();
		}

		// node not found
		return false;
	}

	//traverse the list till you reach a certain number then return the item of the node at that place
	T traverse(int r)
	{
		Node<T>* p = Head;
		for (int i = 0; i < r; i++)
		{
			p = p->getNext();
		}
		return p->getItem();
	}

	// count number of nodes in linked list
	int count()
	{
		int count = 0;
		Node<T>* current = Head;
		while (current != nullptr) {
			count++;
			current = current->getNext();
		}
		return count;
	}

	T getFront() const
	{
		if (Head != nullptr) {
			return Head->getItem();
		}

	}
	Node<T>* gethead() {
		if (Head != nullptr) {
			return Head;
		}
	}
};

#endif	
