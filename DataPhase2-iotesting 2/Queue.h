#pragma once
#include"Node.h"
#include"vector"
using namespace std;
template<typename T>
class Queue {
private:
	Node<T>* front;
	Node<T>* rear;
	int count; //Counter of all elements inside
public:
	Queue() {
		front = nullptr;
		rear = nullptr;
		count = 0;
	}
	bool enqueue(T item) {
		Node<T>* temp = new Node<T>(item);

		if (isEmpty()) {
			front = temp;
			rear = temp;
		}
		else {
			rear->setNext(temp);
		}

		rear = temp;
		rear->setNext(nullptr);
		count++;
		return true;
	}
	T dequeue() {
		if (isEmpty())
			throw std::runtime_error("Queue is empty");

		Node<T>* nodeToDeletePtr = front;
		T item = front->getItem();
		front = front->getNext();
		if (nodeToDeletePtr == rear)
			rear = nullptr;
		delete nodeToDeletePtr;
		count--;

		if (isEmpty())
			rear = nullptr; // Update rear to nullptr if the queue is now empty

		return item;
	}


	bool isEmpty() {
		if (!front)
			return true;
		return false;
	}
	void deletequeue() {
		Node<T>* temp = front;
		while (!isEmpty()) {
			dequeue();
		}
	}
	T peek() {
		if (!front)
			throw std::runtime_error("Queue is empty");

		T item = front->getItem();
		return item;
	}

	~Queue()
	{

		
	}
	Queue(const Queue<T>& LQ) //COPY CONSTRUCTOR
	{
		{
			Node<T>* NodePtr = LQ.front;
			if (!NodePtr) //LQ is empty
			{
				front = rear = nullptr;
				return;
			}

			//insert the first node
			Node<T>* ptr = new Node<T>(NodePtr->getItem());
			front = rear = ptr;
			NodePtr = NodePtr->getNext();

			//insert remaining nodes
			while (NodePtr)
			{
				Node<T>* ptr = new Node<T>(NodePtr->getItem());
				rear->setNext(ptr);
				rear = ptr;
				NodePtr = NodePtr->getNext();
			}
		}
	}

	int getCount()
	{
		return count;
	}
	void printQueue() {
		if (isEmpty()) {
			cout << "empty";
		}
		else {
			Node<T>* temp = front;
			while (temp != nullptr) {
				cout << *temp->getItem() << " ";
				temp = temp->getNext();
			}

		}
	}



	
};