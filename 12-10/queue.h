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
	Node * front;//ͷָ��
	Node * rear;//βָ��
	int items;//�������ж��ٸ�Ԫ��
	const int qsize;//˽�����ݳ�Ա������const���ͣ�ֻ��ͨ����Ա��ʼ���б���г�ʼ��
	Queue(const Queue & q) :qsize(0) {}//���ó�˽�еĸ��ƹ��캯��
	Queue & operator=(const Queue & q) { return *this; }//���ó�˽�е����ظ�ֵ�����
public:
	Queue(int qs = Q_SIZE);
	~Queue();
	bool isempty()const;
	bool isfull()const;
	int queuecount()const;//����Ԫ�ظ���
	bool enqueue(const Item & item);//���Ԫ��
	bool dequeue(Item & item);//ɾ��Ԫ��
};

#endif // !QUEUE_H_
