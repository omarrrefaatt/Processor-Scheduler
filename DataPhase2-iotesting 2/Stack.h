#pragma once
#include <iostream>
using namespace std;
#include "Node.h"
template<typename T>
class Stack
{
	Node<T>* top;
public:
	Stack() : top(nullptr) {}
	void push(T item);
	int pop();
	bool IsEmpty();
	void display();
	int count();
	bool IsFound(T item);
	bool IsFull();

};
