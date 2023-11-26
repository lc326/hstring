#pragma once
#define _CRT_SECURE_NO_WARNINGS

class hstring
{
public:
	//默认构造函数
	hstring();

	//有参构造
	hstring(char* str,int length);

	//拷贝构造
	hstring(const hstring& str);

	//拷贝赋值运算符
	void operator=(const hstring& str);

	//int to hstring
	void operator=(const int a);

	//字符串拼接
	hstring operator+(const hstring& str);

	//字符串查找
	int locate(const hstring& str);

	//字符串修改
	bool update(const hstring& str1, const hstring& str2);

	//字符串删除
	hstring operator-(const hstring& str);

	//输出显示字符串内容
	void printstring();

	int get_size()const;

	int get_capacity()const;

	char* get_string();
	//析构函数
	~hstring();
private:
	//重新分配内存大小
	void recapacity(int size);

	char* my_string;//指向开辟的字符串；
	int m_size;//字符数量
	int m_capacity;//当前开辟内存的大小
};

