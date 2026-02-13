#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<list>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

/*
* list容器：
* 数据结构：双向循环链表
* 迭代器：双向迭代器
* 常用的api：
* 1.构造函数
* 2.插入和删除
* 3.大小操作
* 4.赋值和存取
* 5.排序和反转
*/

//迭代器检验
void test01()
{
	list<int>::iterator it;
	it++;
	it--;
	//it + 2;
	//只能跨前后一个对象，所以不是随机迭代器
}

/*
* 构造
* list<T>l;//无参构造
* list<T>(begin,end);//将一个容器中的begin到end的间的数据拷贝进去
* list<T>(n,elem);//将n个elem元素拷贝进去
* list<T>(const list<T>&l);//拷贝构造
*/

//新知识
//随机迭代器是瞬移，可以it+1,it-1,it++,it+3.....
//双向迭代器是一步一步走，编译器只认识it++,it--、it+1就无法认识

void printMylist(const list<int>& l)
{
	for (list<int>::const_iterator it = l.begin(); it != l.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;
}

void test02()
{
	list<int>mylist1(10, 6);
	list<int>mylist2(mylist1.begin()++, mylist1.end()--);
	printMylist(mylist2);
	
}

bool myfunc(int a)
{
	return a > 300;
}

/*
* 插入和删除操作
* push_back(elem);//尾插
* pop_back();//尾删
* push_front();//头插
* pop_front();//头删
* insert(pos,begin,end);//在对应位置插入另外一个容器的begin到end之间的元素
* insert(pos,n,elem);//在对应位置，插入n个elem
* insert(pos,elem);//在对应位置插入elem
* clear();//删除所有元素
* erase(pos);//删除掉对应位置的元素
* erase(begin,end);//删除掉对应范围内的元素，begin到end-1
* remove(elem);//删除掉该容器中的所有elem
*/

void test03()
{
	list<int>mylist;
	mylist.push_back(10);
	mylist.push_back(20);
	mylist.push_back(30);
	mylist.push_back(40);
	mylist.push_back(50);

	vector<int>v;
	v.push_back(1000);
	v.push_back(2000);
	v.push_back(3000);
	v.push_back(4000);
	v.push_back(5000);

	mylist.insert(++mylist.begin(), v.begin(), v.end());
	printMylist(mylist);

	//删除大于300的数,写一个bool类型的回调函数
	mylist.remove_if(myfunc);
	printMylist(mylist);
}

/*
* 大小操作
* size();//计算容器的大小
* empty();//判断是否为空
* resize(num);//重新定义容器的大小
* //定义大了就默认多出来的空间初始化为0
* //定义小了则删除多出来的部分
* resize(num,elem);///重新定义容器的大小
* //定义大了就默认多出来的空间初始化为elem
* //定义小了则删除多出来的部分
*/

void test04()
{
	list<int>mylist;
	for (int i = 0; i < 10; i++)
	{
		mylist.push_back(i + 1);
	}
	printMylist(mylist);

	cout << "size:" << mylist.size() << endl;

	cout << "empty的值：" << mylist.empty() << endl;
	//说明empty()成立则返回值为0，反之为1
	if (mylist.empty())
	{
		cout << "为空" << endl;
	}

	else
	{
		cout << "不为空" << endl;
	}
}

/*
* 赋值操作和数据的存取
* assign(begin(),end());//将另一个容器的begin到end间的数据给赋值进去
* assign(n,elem);//将n个elem赋值进去
* list&operator=(const list<T>&l);//重载等号运算符
* swap(list);//交换list内的数据
* front();//返回第一个数据
* back();//返回最后一个数据
*/

void test05()
{
	list<int>mylist1;
	mylist1.assign(10, 6);
	printMylist(mylist1);

	list<int>mylist2;
	for (int i = 0; i < 10; i++)
	{
		mylist2.push_back(i + 1);
	}
	printMylist(mylist2);

	mylist2.swap(mylist1);
	printMylist(mylist1);
	printMylist(mylist2);

}

/*
* 反转和排序
* reverse();//反转链表，将list容器中的元素反过来写
* sort();list排序
*/

bool Compare(int a, int b)
{
	return a > b;
}

void test06()
{
	list<int>mylist;
	mylist.push_back(3);
	mylist.push_back(6);
	mylist.push_back(1);
	mylist.push_back(9);
	mylist.push_back(0);
	mylist.push_back(2);
	printMylist(mylist);

	mylist.reverse();
	printMylist(mylist);

	//注意，list里面不能使用算法中的sort，他自带sort成员模板函数
	//sort(mylist.begin(),mylist.end());这个不行

	//使用自带的成员模板函数sort
	mylist.sort();
	printMylist(mylist);
	//这个是从小到大的排序

	//从大到小的排序也可以实现，用到回调函数
	mylist.sort(Compare);
	printMylist(mylist);
	
}

int main()
{
	test02();
	test03();
	test04();
	test05();
	test06();

	return 0;
}