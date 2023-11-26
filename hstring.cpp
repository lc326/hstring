
#include "hstring.h"
#include<memory>
hstring::hstring():m_size(0),m_capacity(4)
{
	my_string = new char[4];
}

hstring::hstring(char* str, int length)
{
	m_capacity = length;
	m_size = length;
	my_string = new char[m_capacity];
	memmove(my_string, str, m_size);
}


hstring::hstring(const hstring& str):m_capacity(str.get_capacity()),m_size(str.get_size())
{
	my_string = new char[m_capacity];
	memmove(my_string, str.my_string, str.get_size());
}

void hstring::operator=(const hstring& str)
{
	m_size = str.m_size;
	recapacity(m_size);
	//void *memmove( void *dest, const void *src, size_t count );
	memmove(my_string, str.my_string, m_size);
	
}

void hstring::operator=(const int a)
{
	int n = 0;//a有多少位
	int rec = a;
	int dev = 1;
	char c;
	while (a / dev != 0)
	{
		++n;
		dev *= 10;
	}
	m_size = n;
	recapacity(m_size);
	dev /= 10;
	for(int i=0;i<n;++i)
	{
		c = (char)(rec / dev + '0');
		rec %= dev;
		dev /= 10;
		memmove(my_string + i, &c, 1);
	}
}

hstring hstring::operator+(const hstring& str)
{
	hstring temp(*this);
	temp.recapacity(m_size + str.m_size);
	temp.m_size = m_size + str.m_size;
	memmove(temp.my_string + m_size,str.my_string,str.m_size );
	return temp;
}

int hstring::locate(const hstring& str)
{
	if (m_size < str.m_size)
		return -1;
	for (int i = 0; i < m_size-str.m_size+1; ++i) {
		for (int j = 0; j <= str.m_size; ++j)
		{
			
			if (j == str.m_size)
				return i;
			if (my_string[i + j] == str.my_string[j])
			{
				continue;
			}
			else
				break;
		}

	}
	return -1;
}

bool hstring::update(const hstring& str1, const hstring& str2)
{
	int loc = locate(str1);
	if (loc == -1) {
		return false;
	}

	else
	{
		m_size = m_size - str1.m_size + str2.m_size;
		recapacity(m_size);
		memmove(my_string + loc + str2.m_size, my_string + loc + str1.m_size, m_size - loc -1);
		memmove(my_string + loc, str2.my_string, str2.m_size);

		return true;
	}
}

hstring hstring::operator-(const hstring& str)
{
	hstring temp(*this);
	int loc = locate(str);
	if (loc == -1) {
		printf("-  false");
		return temp;
	}
	
	temp.m_size -= str.m_size;
	memmove(temp.my_string + loc, temp.my_string + loc+ str.m_size, temp.m_size);
	return temp;
}

void hstring::printstring()
{
	for (int i = 0; i < m_size; ++i) {
		printf( "%c",my_string[i]);
	}
	printf("\n");
}

int hstring::get_size()const
{
	return m_size;
}

int hstring::get_capacity()const
{
	return m_capacity;
}

char* hstring::get_string()
{
	return my_string;
}

hstring::~hstring()
{
	delete[] my_string;
	my_string = nullptr;
}

void hstring::recapacity(int size)
{
	int flag = 0;
	while (m_capacity < size) {
		m_capacity *= 2;
		flag = 1;
	}
	if (flag == 1) {
		char* newstr = new char[m_capacity];
		//void *memmove( void *dest, const void *src, size_t count );
		memmove(newstr,my_string,m_size);
		char *p = my_string;
		my_string = newstr;
		delete[] p;
	}

}


