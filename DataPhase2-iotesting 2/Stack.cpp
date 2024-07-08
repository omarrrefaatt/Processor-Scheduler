#include "Stack.h"
template<typename T>
void Stack<T>::push(T item) {
	Node<T>* newnode = new Node<T>;
	newnode->data = item;
	if (IsEmpty()) {
		newnode->next = nullptr;
		top = newnode;
	}
	else {
		newnode->next = top;
		top = newnode;

	}
}
template<typename T>
int Stack<T>::pop() {
	int value;
	Node<T>* delptr = top;
	value = top->data;
	top = top->next;
	delete delptr;
	return value;
}
template<typename T>
int Stack<T>::count() {
	int counter = 0;
	Node<T>* temp = top;
	while (temp != nullptr) {
		counter++;
		temp = temp->next;
	}
	return counter;
}
template<typename T>
bool Stack<T>::IsFull() {
	Node<T>* ptr = new Node<T>;
	if (ptr == nullptr)
		cout << "the stack is full,cannot add more items\n";
}

template<typename T>
bool Stack<T>::IsEmpty() {
	if (top == nullptr)
		return true;
	else
		return false;

}
template<typename T>
void Stack<T>::display() {
	Node<T>* temp = top;
	while (temp != nullptr) {
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}
