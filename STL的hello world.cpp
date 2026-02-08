#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <vector>//引入模板类容器
#include<algorithm>//算法的头文件
#include<string>
using namespace std;


//加入算法的回调函数
//回调函数就是不是让你直接调用的函数，而是交给另一个函数调用的函数
void myPrint(int val)
{
	cout << val<<" ";
}

class Maker
{
	friend ostream& operator<<(ostream& out, const Maker& m);
public:

	Maker(string name, int age)
	{
		this->age = age;
		this->name = name;
	}
private:
	string name;
	int age;
};
ostream& operator<<(ostream& out,const Maker &m)
{
	out << "name:" << m.name << " " << "age:" << m.age << endl;
	return out;
}
void test01()
{
	vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);

	//获取开始位置的迭代器
	vector<int>::iterator begin = v.begin();
	//获取结束位置的迭代器
	vector<int>::iterator end = v.end();

	//遍历算法
	for_each(begin,end, myPrint);
	//函数名本身就是指针，这传进去的是该函数的指针，告诉这个函数要调用的函数位置在哪里
	cout << endl;
}

void test02()
{
	vector<Maker> v2;
	//往容器中存储对象
	v2.push_back(Maker("悟空", 18));
	v2.push_back(Maker("Lily", 20));
	v2.push_back(Maker("Susan", 28));

	//获取首尾迭代器
	vector<Maker>::iterator begin = v2.begin();
	vector<Maker>::iterator end = v2.end();

	//打印容器中的对象
	while (begin != end)
	{
		cout << (*begin); //重载<<
		begin++;
	}
}

//存储对象的指针
void test03()
{
	//创建容器
	vector<Maker*> v3;
	Maker* m1 = new Maker("悟空", 18);
	Maker* m2 = new Maker("Lily", 20);
	Maker* m3 = new Maker("Susan", 28);

	//放入数据
	v3.push_back(m1);
	v3.push_back(m2);
	v3.push_back(m3);

	//用迭代器接首尾指针
	vector<Maker*>::iterator begin = v3.begin();
	vector<Maker*>::iterator end = v3.end();

	//打印数据
	while (begin != end)
	{
		cout << **begin;
		++begin;
	}

	delete m1;
	m1 = NULL;
	delete m2;
	m2 = NULL;
	delete m3;
	m3 = NULL;
}

//容器嵌套容器
void test04()
{
	//创建容器
	vector<vector<int>> vs;
	//创建元素内容
	vector<int>v1;
	vector<int>v2;
	vector<int>v3;
	vector<int>v4;
	vector<int>v5;
	//给元素给予元素
	for (int i = 0; i < 5; i++)
	{
		v1.push_back(i + 10);
		v2.push_back(i + 10);
		v3.push_back(i + 10);
		v4.push_back(i + 10);
		v5.push_back(i + 10);
	}

	//把小容器放到大容器当中
	vs.push_back(v1);
	vs.push_back(v2);
	vs.push_back(v3);
	vs.push_back(v4);
	vs.push_back(v5);

	//获取大容器中的迭代器
	vector<vector<int>>::iterator begin1 = vs.begin();
	vector<vector<int>>::iterator end1 = vs.end();

	//二重遍历
	while (begin1 != end1)
	{
		//获取小容器的迭代器
		vector<int>::iterator begin2 = (*begin1).begin();
		vector<int>::iterator end2 = (*begin1).end();
		//打印小容器中的数据
		for_each(begin2, end2, myPrint);
		++begin1;
	}
	
}

int main()
{
	test01();
	test02();
	test03();
	test04();
	return 0;
}