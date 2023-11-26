#include "hstring.h"
#include<iostream>

int main()
{
	char c[] = "hello";
	hstring mystr(c, sizeof(c)-1);

	//test1 for ¹¹Ôìº¯Êý,operator=
	/*std::cout << mystr.get_size() << std::endl;
	std::cout << mystr.get_capacity() << std::endl;
	mystr.printstring();
	mystr = mystring;
	std::cout << mystring.get_size() << std::endl;
	std::cout << mystring.get_capacity() << std::endl;
	mystring.printstring();
	std::cout << mystr.get_size() << std::endl;
	std::cout << mystr.get_capacity() << std::endl;*/

	//test2 for operator+
	/*char b[] = "world";
	hstring mystr2(b, sizeof(b) - 1);
	hstring mystr3 = mystr + mystr2;
	std::cout << mystr3.get_size() << std::endl;
	std::cout << mystr3.get_capacity() << std::endl;
	mystr3.printstring();*/

	//test3 for locate
	/*char a1[] = "helloworld";
	char a2[] = "worldhelloworld";
	char a3[] = "hell";
	hstring mystr1(a1, sizeof(a1) - 1);
	hstring mystr2(a2, sizeof(a2) - 1);
	hstring mystr3(a3, sizeof(a3) - 1);
	int Loc = mystr2.locate(mystr);
	std::cout << Loc << std::endl;
	Loc = mystr1.locate(mystr);
	std::cout << Loc << std::endl;
	Loc = mystr3.locate(mystr);
	std::cout << Loc << std::endl;*/

	//test4 for operator -
	/*char a1[] = "helloworld123";
	hstring mystr1(a1, sizeof(a1) - 1);
	hstring mystr2 = mystr1 - mystr;
	mystr2.printstring();*/

	//test5 for update
	/*char a1[] = "helloworld123";
	hstring mystr1(a1, sizeof(a1) - 1);
	char a2[] = "HELLO!";
	hstring mystr2(a2, sizeof(a2) - 1);
	mystr1.update(mystr, mystr2);
	std::cout << mystr1.get_size() << std::endl;
	std::cout << mystr1.get_capacity() << std::endl;
	mystr1.printstring();*/

	//test5 for operator=(const int a)
	mystr = 123456;
	mystr.printstring();
	std::cout << mystr.get_size() << std::endl;
	std::cout << mystr.get_capacity() << std::endl;


	system("pause");
}