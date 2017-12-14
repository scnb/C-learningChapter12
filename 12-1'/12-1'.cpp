//12-1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "stringbad.h"
#include <iostream>

using std::cout;


void callme1(StringBad &);//引用传递
void callme2(StringBad);//值传递

int main()
{
	using std::endl;
	{
		cout << "Starting an inner block.\n";
		StringBad headline1("Celery Stalks at Midnight");
		StringBad headline2("Lettuce Prey");
		StringBad sports("Spinach Leaves Bowl for Dollars");
		cout << "headline1: " << headline1 << endl;
		cout << "headline2: " << headline2 << endl;
		cout << "sports: " << sports << endl;
		callme1(headline1);
		cout << "headline1: " << headline1 << endl;
		callme2(headline2);
		cout << "headline2: " << headline2 << endl;
		cout << "Initialize one object to another:\n";
		StringBad sailor = sports;
		cout << "sailor: " << sailor << endl;
		StringBad knot;
		knot = headline1;
		cout << "knot: " << knot << endl;
		cout << "Exiting the block.\n";
	}
	cout << "End of main()\n";
	return 0;                                          
}

void callme1(StringBad & rsb)
{
	cout << "String passed by reference:\n";
	cout << "     \""<<rsb << "\"\n";
}

void callme2(StringBad rsb)
{
	cout << "String passed by value:\n";
	cout << "      \"" << rsb << "\"\n";
}