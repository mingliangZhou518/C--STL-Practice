#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stack>
#include<queue>
using namespace std;

/*
* stack容器：
* 数据结构：连续的存储空间，只有一个出口，遵循先进的后出的顺序
* 迭代器：没有迭代器
* 常用的api：
* 1.构造函数
* 2.赋值操作
* 3.数据存储
* 4.大小操作
*/

/*
* queue容器：
* 数据结构：连续的存储空间，有两个口，遵循先进的先出，后进的后出的特性
* 迭代器：没有迭代器
* 常用的api：
* 1.构造函数
* 2.存取、插入和删除操作
* 3.赋值操作
* 4.大小操作
* 
*/

/*
* 栈容器：先进后出
*/

//存储基础数据类型

//遍历基础数据类型
void basic_printStack(stack<int>& s)
{
	while (!s.empty())
	{
		cout << s.top() << " ";
		s.pop();//每次pop出去，size都会减小
	}
	cout << endl;
}

void test01()
{
	stack<int> s;
	for (int i = 0; i < 5; i++)
	{
		s.push((i + 1) * 10);
	}
	basic_printStack(s);
}

//存储类
class Student
{
public:
	friend void class_printStack(stack<Student>& s);
	friend void class_printQueue(queue<Student>q);
	Student(string name, int age)
	{
		this->name = name;
		this->age = age;
	}
private:
	string name;
	int age;
};

void class_printStack(stack<Student>& s)
{
	while (!s.empty())
	{
		cout << "name:" << s.top().name << " " << "age:" << s.top().age<<endl;
		s.pop();
	}

}

void test02()
{
	stack<Student> s;
	s.push(Student("aaa", 18));
	s.push(Student("bbb", 19));
	s.push(Student("ccc", 20));
	class_printStack(s);
	
}

//queue容器
//存储基本类型

void basic_printQueue(queue<int>& q)
{
	cout << "front:" << q.front() << endl;
	cout << "back:" << q.back() << endl;
	while (!q.empty())
	{
		cout << q.front() << " ";
		q.pop();
	}
	cout << endl;
}

void test03()
{
	queue<int>q;
	for (int i = 0; i < 5; i++)
	{
		q.push(i + 1);
	}
	basic_printQueue(q);
}

//打印类

void class_printQueue(queue<Student>q)
{
	cout << "front name:" << q.front().name << " " << "front age:" << q.front().age << endl;
	cout << "back name:" << q.back().name << " " << "back age:" << q.back().age << endl;

	while (!q.empty())
	{
		cout << q.front().name << " " << q.front().age << endl;
		q.pop();
	}
}
void test04()
{
	queue<Student>q;
	q.push(Student("aaa", 18));
	q.push(Student("bbb", 19));
	q.push(Student("ccc", 20));
	q.push(Student("ddd", 21));
	q.push(Student("eee", 22));
	class_printQueue(q);
}

int main()
{
	test01();
	test02();
	test03();
	test04();
	return 0;
}