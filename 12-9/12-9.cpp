// 12-9.cpp : 定义控制台应用程序的入口点。
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
	JustTesting(const string & s = "Just Testing", int n = 0)//显示构造函数
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
	pc1 = new(buffer)JustTesting;//用定位new运算符来分配空间
	pc2 = new JustTesting("Heap1", 20);//用普通new运算符来分配空间
	cout << "Memory block addresses:\n" << "buffer: " << (void *)buffer << "    heap: " << pc2 << endl;//显示buffer的地址和pc2的地址，进行对比
	cout << "Memory contents:\n";
	cout << pc1 << ": ";//显示pc1的地址
	pc1->show();
	cout << pc2 << ": ";
	pc2->show();
	JustTesting *pc3, *pc4;
	pc3 = new (buffer+sizeof(JustTesting)) JustTesting("Bad Idea", 6);//再次用定位new运算符分配空间，覆盖了原来的pc1
	pc4 = new JustTesting("Heap2", 10);
	cout << "Memory contents:\n";
	cout << pc3 << ": ";//pc3的地址应该和上面的pc1的地址是一样的
	pc3->show();
	cout << pc4 << ": ";
	pc4->show();
	delete pc2;
	delete pc4;
	pc1->~JustTesting();
	pc3->~JustTesting();
	delete[] buffer;//必须要先删除pc1，再删除pc2，最后删除buffer，以避免依赖关系的影响
	cout << "Done\n";
	getchar();
	return 0;
}
