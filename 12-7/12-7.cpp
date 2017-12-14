// 12-7.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "string2.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

const int ArSize = 10;
const int MaxLen = 81;

int main()
{
	using namespace std;
	String name;
	cout << "Hi,what's your name?\n";
	cin >> name;
	cout << name << ", please enter up to " << ArSize << " short sayings <empty line to quit>:\n";
	String sayings[ArSize];
	char temp[MaxLen];
	int i;
	for (i = 0;i < ArSize;i++)
	{
		cout << i + 1 << "; ";
		cin.get(temp, MaxLen);
		while (cin&&cin.get() != '\n')
		{
			continue;
		}
		if (!cin || temp[0] == '\0')
		{
			break;
		}
		else
		{
			sayings[i] = temp;
		}
	}
		int total = i;
		if (total > 0)
		{
			cout << "Here are your sayings:\n";
			for (i = 0;i < total;i++)
			{
				cout << sayings[i] << "\n";
			}
			//ʹ��ָ����׷����̵��ַ���������ĸ�ǰ���ַ���
			String * shortest = &sayings[0];
			String * first = &sayings[0];
			for (i = 1;i < total;i++)
			{
				if (sayings[i].length() < shortest->length())
				{
					shortest = &sayings[i];
				}
				if (sayings[i] < *first)
				{
					first = &sayings[i];
				}
			}
			cout << "Shortest sayings:\n" << *shortest << endl;
			cout << "First sayings:\n" << *first << endl;
			srand(time(0));
			int choice = rand() % total;
			//ʹ��new���������������ʼ���µ�String����
			String * favorite = new String(sayings[choice]);
			cout << "My favorite saying:\n" << *favorite << endl;
			delete favorite;
		}
		else
		{
			cout << "No much to say,en?\n";
		}
		cout << "Bye.\n";
		getchar();
		getchar();
		return 0;
}

