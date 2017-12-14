#include "stdafx.h"
#include "string2.h"
#include <iostream>
#include <cstring>
using std::cin;
using std::cout;
using std::istream;
using std::ostream;

int String::num_strings = 0;

String::String()
{
	len = 4;
	str = new char[1];
	str[0] = '\0';
	num_strings++;
}

String::String(const char * s)//该构造函数是用在将C风格字符串赋值String对象时
{
	len = strlen(s);
	str = new char[len + 1];
	std::strcpy(str, s);
	num_strings++;
}

int String::HowMany()
{
	return num_strings;
}

String::~String()
{
	--num_strings;
	delete[] str;
}

String::String(const String & st)//该构造函数是用在  将String对象赋值给另一个String对象时
{
	num_strings++;
	len = st.len;
	str = new char[len + 1];
	std::strcpy(str, st.str);
}

String & String::operator = (const String & st)//该赋值运算符用于同String对象间的赋值
{
	if (this == &st)
	{
		return *this;
	}
	delete[] str;
	len = st.len;
	str = new char[len + 1];
	std::strcpy(str, st.str);
	return *this;
}

String & String::operator = (const char * s)//该赋值运算符用于把C风格字符串赋给String对象
{
	delete[] str;
	len = strlen(s);
	str = new char[len + 1];
	std::strcpy(str, s);
	return *this;
}

char & String::operator[](int i)//既可读、又可写元素
{
	return str[i];
}

const char & String::operator[](int i)const//只可读，不可写，加const限定符就是为了防止元素被修改
{
	return str[i];
}

bool operator<(const String & st1, const String & st2)
{
	return (std::strcmp(st1.str, st2.str) < 0);
}

bool operator>(const String & st1, const String & st2)
{
	return st2 < st1;
}

bool operator==(const String & st1, const String & st2)
{
	return (std::strcmp(st1.str, st2.str) == 0);
}

ostream & operator<<(ostream & os, const String & st)
{
	os << st.str;
	return os;
}

istream & operator >> (istream & is, String & st)//绝对不能在重载>>运算符时加const，不然没法修改了
{
	char temp[String::CINLIM];
	is.get(temp, String::CINLIM);
	if (is)
	{
		st = temp;//使用重载的赋值运算符，将C风格字符串赋给String变量
	}
	while (is&&is.get() != '\n')
	{
		continue;
	}
	return is;
}