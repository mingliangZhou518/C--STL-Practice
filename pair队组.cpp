#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;

/*
* 队组是一个类，类中有两个公有的成员变量
* 一般来接受编号和数据两种
*/

void test01()
{
	pair<int, string>myp(1, "悟空");
	cout << "编号:" << myp.first << " " << "内容：" << myp.second << endl;
}

int main()
{
	test01();

	return 0;
}