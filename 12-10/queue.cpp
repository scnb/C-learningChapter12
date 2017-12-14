#include "stdafx.h"
#include "queue.h"
#include <iostream>
#include <cstdlib>

Queue::Queue(int qs) : qsize(qs)
{
	front = rear = NULL;
	items = 0;
}

Queue::~Queue()
{
	Node * temp;
	while (front != NULL)
	{
		temp = front;
		front = front->next;
		delete temp;
	}
}

bool Queue::isempty()const
{
	return items == 0;//注意这里是==，是判断是否相等，而不是赋值，如果相等，说明队列为空
}

bool Queue::isfull()const
{
	return items == qsize;
}

int Queue::queuecount()const
{
	return items;
}

bool Queue::enqueue(const Item & item)
{
	if (isfull())
	{
		return false;
	}
	Node * add = new Node;
	add->next = NULL;
	add->item = item;
	items++;
	if (front == NULL)//如果队列一个元素也没有，就让该结点成为首结点
	{
		front = add;
	}
	else
	{
		rear->next = add;
	}
	rear = add;//让尾指针指向add
	return true;

}

bool Queue::dequeue(Item & item)
{
	if (front == NULL)
	{
		return false;
	}
	item = front->item;
	items--;
	Node * temp = front;
	front = front->next;
	delete temp;
	if (items == 0)
	{ 
		rear = NULL;
	}
	return true;
}

void Customer::set(long when)
{
	processtime = std::rand() % 3 + 1;//等待时间
	arrive = when;//到达时间
}
