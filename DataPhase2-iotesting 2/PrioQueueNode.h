#pragma once
template <typename T>
class PriorityNode
{
private:
	T  item;
	PriorityNode<T>* next;
	int priority;
public:
	/*PriorityNode(const T & X, int k, PriorityNode<T>* j = nullptr)
	{
		item = X;
		priority = k;
		next = j;
	}*/
	PriorityNode(const  T& X, int k)
	{
		item = X;
		priority = k;
		next = nullptr;
	}
	//PriorityNode()
	//{
	//	next = nullptr;
	//}
	void setPriority(int k)
	{
		priority = k;
	}
	int getPriority() const
	{
		return priority;
	}
	void setNext(PriorityNode<T>* j)
	{
		next = j;
	}
	PriorityNode<T>* getNext() const
	{
		return next;
	}
	void setItem(const T& a)
	{
		item = a;
	}
	T getItem() const
	{
		return  item;
	}
};