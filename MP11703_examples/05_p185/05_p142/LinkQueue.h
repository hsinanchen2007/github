#pragma once
#ifndef LINKQUEUE_H  
#define LINKQUEUE_H  

#include <iostream>  
#include <assert.h>  
using namespace std;

template <class T>
class LinkQueue {

	struct LinkQueueNode
	{
		T    data;
		LinkQueueNode *link;
		LinkQueueNode(T & theData, LinkQueueNode * n = NULL) : data(theData), link(n) { }
	};
	LinkQueueNode* front;
	LinkQueueNode* back;

public:
	LinkQueue();
	~LinkQueue();
	void EnQueue(T& element);
	T DelQueue();
	T& GetFront();
	void MakeEmpty();
	bool IsEmpty();
};

template <class T>
LinkQueue<T>::LinkQueue()
{
	front = back = NULL;
}

template <class T>
LinkQueue<T>::~LinkQueue()
{
	this->MakeEmpty();
}

template <class T>
void LinkQueue<T>::EnQueue(T& value)
{
	if (this->IsEmpty())
		front = back = new LinkQueueNode(value);
	else
		back = back->link = new LinkQueueNode(value);
}

template <class T>
T LinkQueue<T>::DelQueue()
{
	LinkQueueNode* old = front;
	T data = old->data;
	front = front->link;
	delete old;
	return data;
}

template <class T>
T& LinkQueue<T>::GetFront()
{
	assert(!IsEmpty());
	return front->data;
}

template <class T>
void LinkQueue<T>::MakeEmpty()
{
	while (!this->IsEmpty()) {
		this->DelQueue();
	}
}

template <class T>
bool  LinkQueue<T>::IsEmpty()
{
	return front == NULL;
}
#endif  
