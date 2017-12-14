#pragma once
#ifndef QUEUE_H_
#define QUEUE_H_

class Customer
{
private:
	long arrive;
	int processtime;
public:
	Customer() { arrive = processtime = 0; }
	void set(long when);
	long when() const { return arrive; }
	int ptime() const { return processtime; }
};

typedef Customer Item;

class Queue
{
private:
	struct Node { Item item;struct Node * next; };
	enum { Q_SIZE = 10 };
	Node * front;//头指针
	Node * rear;//尾指针
	int items;//队列种有多少个元素
	const int qsize;//私有数据成员，还是const类型，只能通过成员初始化列表进行初始化
	Queue(const Queue & q) :qsize(0) {}//设置成私有的复制构造函数
	Queue & operator=(const Queue & q) { return *this; }//设置成私有的重载赋值运算符
public:
	Queue(int qs = Q_SIZE);
	~Queue();
	bool isempty()const;
	bool isfull()const;
	int queuecount()const;//返回元素个数
	bool enqueue(const Item & item);//添加元素
	bool dequeue(Item & item);//删除元素
};

#endif // !QUEUE_H_
