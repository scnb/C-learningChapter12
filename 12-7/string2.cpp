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

String::String(const char * s)//�ù��캯�������ڽ�C����ַ�����ֵString����ʱ
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

String::String(const String & st)//�ù��캯��������  ��String����ֵ����һ��String����ʱ
{
	num_strings++;
	len = st.len;
	str = new char[len + 1];
	std::strcpy(str, st.str);
}

String & String::operator = (const String & st)//�ø�ֵ���������ͬString�����ĸ�ֵ
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

String & String::operator = (const char * s)//�ø�ֵ��������ڰ�C����ַ�������String����
{
	delete[] str;
	len = strlen(s);
	str = new char[len + 1];
	std::strcpy(str, s);
	return *this;
}

char & String::operator[](int i)//�ȿɶ����ֿ�дԪ��
{
	return str[i];
}

const char & String::operator[](int i)const//ֻ�ɶ�������д����const�޶�������Ϊ�˷�ֹԪ�ر��޸�
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

istream & operator >> (istream & is, String & st)//���Բ���������>>�����ʱ��const����Ȼû���޸���
{
	char temp[String::CINLIM];
	is.get(temp, String::CINLIM);
	if (is)
	{
		st = temp;//ʹ�����صĸ�ֵ���������C����ַ�������String����
	}
	while (is&&is.get() != '\n')
	{
		continue;
	}
	return is;
}