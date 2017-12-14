
// 12-10.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "queue.h"
#include <cstdlib>
#include <iostream>
#include <ctime>

bool newcustomer(double x);

const int MIN_PER_HR = 60;//一个小时有60分钟

int main()
{
	using std::cin;
	using std::cout;
	using std::endl;
	using std::ios_base;
	std::srand(std::time(0));
	cout << "Case Study:Bank of Heather Automatic Teller\n";
	cout << "Enter maximum size of queue:";
	int qs;
	cin >> qs;
	Queue line(qs);
	cout << "Enter the number of simulation hours:";
	int hours;
	cin >> hours;
	long cyclelimit = MIN_PER_HR*hours;//因为一次循环是一分钟时间，所以总的分钟数就是总的循环次数
	cout << "Enter the average number of customers per hour:";
	double perhour;
	cin >> perhour;
	double min_per_cust;
	min_per_cust = MIN_PER_HR / perhour;//一个小时的时间除以在这一小时里有多少人来到，即每个人占用几分钟
	Item temp;//新客人的信息
	long turnaways = 0;//因队列已满而离开的
	long customers = 0;//进入队列的人数
	long served = 0;//接收服务的人数
	long sum_line = 0;//计算队列的长度
	int wait_time = 0;//一个客人的等待时间
	long line_wait = 0;//计算在队列里等待的时间
	//开始模拟
	for (int cycle = 0;cycle < cyclelimit;cycle++)
	{
		if (newcustomer(min_per_cust))//如果有客人来到
		{
			if (line.isfull())
			{
				turnaways++;
			}
			else
			{
				customers++;
				temp.set(cycle);
				line.enqueue(temp);//将temp添加到队列末尾
			}
		}
		if (wait_time <= 0 && !line.isempty())//如果队列不为空，并且等待时间已经减到0了，则应该出对了
		{
			line.dequeue(temp);
			wait_time = temp.ptime();
			line_wait += cycle - temp.when();//cycle其实也和实时时间一致，减去到达时间就是在队列种的等待时间
			served++;
		}
		if (wait_time > 0)//等待时间大于0，即处于等待中，一次cycle就让wait_time减一，代表过去了一分钟
		{
			wait_time--;
		}
		sum_line += line.queuecount();//计算队列中的总人数
	}
	//报告结果
	if (customers > 0)
	{
		cout << "Customers accepted: " << customers << endl;
		cout << "  Customers served: " << served << endl;
		cout << "         turnaways: " << turnaways << endl;
		cout << "average queue size: ";
		cout.precision(2);//设置小数点为2位
		cout.setf(ios_base::fixed, ios_base::floatfield);
		cout << (double)sum_line / cyclelimit << endl;
		cout << " average wait time: " << (double)line_wait / served << " minutes\n";
	}
	else
	{ 
		cout << "No customers!\n";
	}
	cout << "Done!\n";
	getchar();
	getchar();
    return 0;
}

bool newcustomer(double x)//x是相邻客户到达的平均时间间隔
{
	return (std::rand()*x / RAND_MAX < 1);
}

