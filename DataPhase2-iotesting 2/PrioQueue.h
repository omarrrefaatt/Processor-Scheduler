#pragma once
#include "PrioQueueNode.h"
#include"iostream"

using namespace std;
template <typename T>
class PriorityQueue
{
private:
	PriorityNode<T>* frontPtr;
	int count;
public:
	int getCount() const
	{
		return count;
	}
	PriorityQueue()
	{
		frontPtr = nullptr;
		count = 0;
	}
	bool isEmpty() const
	{
		return !count;
	}
	bool enqueue(const T& newEntry, int pr)
	{
		PriorityNode<T>* newPtr = new PriorityNode<T>(newEntry, pr);

		if (isEmpty() || pr < frontPtr->getPriority())
		{
			newPtr->setNext(frontPtr);
			frontPtr = newPtr;
			count++;
			return true;
		}

		PriorityNode<T>* ptr = frontPtr;
		while (ptr->getNext() && ptr->getNext()->getPriority() <= pr)
			ptr = ptr->getNext();

		newPtr->setNext(ptr->getNext());
		ptr->setNext(newPtr);
		count++;
		return true;
	}


	T dequeue() {
		if (isEmpty()) {
			throw std::runtime_error("Queue is empty!");
		}

		PriorityNode<T>* nodeToDeletePtr = frontPtr;
		T frntEntry = frontPtr->getItem();
		frontPtr = frontPtr->getNext();

		delete nodeToDeletePtr;
		count--;

		return frntEntry;
	}

	bool peekFront(T& frntEntry) const
	{
		if (isEmpty())
			return false;

		frntEntry = frontPtr->getItem();
		return true;

	}

	T* toArray()
	{
		if (!frontPtr)
			return nullptr;

		T* Arr = new T[count];
		PriorityNode<T>* p = frontPtr;
		for (int i = 0; i < count; i++)
		{
			Arr[i] = p->getItem();
			p = p->getNext();
		}
		return Arr;
	}
	void printQueue() const {
		if (isEmpty()) {
			cout << " empty";
		}
		else {
			PriorityNode<T>* temp = frontPtr;
			while (temp != nullptr) {
				cout << *temp->getItem();
				temp = temp->getNext();
			}
		}
	}


};