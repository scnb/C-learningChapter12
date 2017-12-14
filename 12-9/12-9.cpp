// 12-9.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include <new>
using namespace std;
const int BUF = 512;

class JustTesting
{
private:
	string words;
	int number;
public:
	JustTesting(const string & s = "Just Testing", int n = 0)//��ʾ���캯��
	{
		words = s;
		number = n;
		cout << words << " constructed\n";
	}
	~JustTesting()
	{
		cout << words << " destroyed\n";
	}
	void show()const { cout << words << ", " << number << endl; }
};

int main()
{
	char * buffer = new char[BUF];
	JustTesting * pc1, *pc2;
	pc1 = new(buffer)JustTesting;//�ö�λnew�����������ռ�
	pc2 = new JustTesting("Heap1", 20);//����ͨnew�����������ռ�
	cout << "Memory block addresses:\n" << "buffer: " << (void *)buffer << "    heap: " << pc2 << endl;//��ʾbuffer�ĵ�ַ��pc2�ĵ�ַ�����жԱ�
	cout << "Memory contents:\n";
	cout << pc1 << ": ";//��ʾpc1�ĵ�ַ
	pc1->show();
	cout << pc2 << ": ";
	pc2->show();
	JustTesting *pc3, *pc4;
	pc3 = new (buffer+sizeof(JustTesting)) JustTesting("Bad Idea", 6);//�ٴ��ö�λnew���������ռ䣬������ԭ����pc1
	pc4 = new JustTesting("Heap2", 10);
	cout << "Memory contents:\n";
	cout << pc3 << ": ";//pc3�ĵ�ַӦ�ú������pc1�ĵ�ַ��һ����
	pc3->show();
	cout << pc4 << ": ";
	pc4->show();
	delete pc2;
	delete pc4;
	pc1->~JustTesting();
	pc3->~JustTesting();
	delete[] buffer;//����Ҫ��ɾ��pc1����ɾ��pc2�����ɾ��buffer���Ա���������ϵ��Ӱ��
	cout << "Done\n";
	getchar();
	return 0;
}
