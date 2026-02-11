#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Maker
{
public:
	Maker(int age)
	{
		this->age = age;
	}
	Maker(const Maker& m)
	{
		cout << "拷贝构造" << endl;
	}
public:
	int age;
};

void test01()
{
	Maker m(10);
	//把对象放到容器当中其实是拷贝了一份进去
	vector<Maker>vec;
	vec.push_back(m);//这里是浅拷贝
	//要注意要有可以调用的拷贝构造函数
	//要注意析构时可能出现的同一份空间释放两次
}
int main()
{
	test01();

	return 0;
}