#pragma once
#define _CRT_SECURE_NO_WARNINGS

class hstring
{
public:
	//Ĭ�Ϲ��캯��
	hstring();

	//�вι���
	hstring(char* str,int length);

	//��������
	hstring(const hstring& str);

	//������ֵ�����
	void operator=(const hstring& str);

	//int to hstring
	void operator=(const int a);

	//�ַ���ƴ��
	hstring operator+(const hstring& str);

	//�ַ�������
	int locate(const hstring& str);

	//�ַ����޸�
	bool update(const hstring& str1, const hstring& str2);

	//�ַ���ɾ��
	hstring operator-(const hstring& str);

	//�����ʾ�ַ�������
	void printstring();

	int get_size()const;

	int get_capacity()const;

	char* get_string();
	//��������
	~hstring();
private:
	//���·����ڴ��С
	void recapacity(int size);

	char* my_string;//ָ�򿪱ٵ��ַ�����
	int m_size;//�ַ�����
	int m_capacity;//��ǰ�����ڴ�Ĵ�С
};

