#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<map>//multimap也是这个头文件
using namespace std;

/*
* map和multimap容器也是关联式容器，容器有自身规则，装的内容是队组，队组的first是键值，second是实值
* 键值无法改变，实值可以改变
* 数据结构：平衡二叉树
* 迭代器：双向迭代器
* map容器和multimap容器的区别是multimap容器允许有相同的元素
* 
* 常用的api：
* 1.构造
* 2.赋值
* 3.大小
* 4.插入
* 5.删除
* 6.查找
* 
*/

//迭代器测试
void test01()
{
	map<int, string>::iterator it;
	it++;
	it--;
	//it + 1;error
	//证明是双向迭代器
}

/*
* 构造函数
* 赋值操作
* 大小操作和前面的容器一样
*/

/*
* 插入操作
* insert(...),往容器中插入元素，返回的是pair<iterator,bool>
* map<int,string>mapStu;
* 第一种，通过pair匿名构造插入
* mapStu.insert(pair<int,string>(1,"张三"))；
* 第二种，通过库函数直接创建pair对象
* mapStu.insert(make_pair(1,"张三"));
* 第三种，通过vaule_type的方式插入对象
* mapStu.insert(map<int,string>::value_type(1，"张三"));
* 第四种，通过数组的方式插入
* mapStu[3]="张三";
* mapStu[4]="李四";
* 
*/

void printMap(const map<int, string>& mymap)
{
	for (map<int, string>::const_iterator it = mymap.begin(); it != mymap.end(); ++it)
	{
		cout << it->first << " " << it->second << endl;
	}
	
}

void test02()
{
	map<int, string>mymap;
	mymap.insert(pair<int, string>(3, "aaa"));

	mymap.insert(make_pair(6, "bbb"));

	mymap.insert(map<int, string>::value_type(2, "ccc"));

	mymap[4] = "ddd";
	printMap(mymap);
	//根据键值从小到大排序
}

//可以像set容器那样通过结构体改变容器规则
struct myfunc
{
	bool operator()(const int& key1, const int& key2)const
	{
		return key1 > key2;
	}
};

template <typename T>
void printMap2(T& mymap)
{
	for (map<int, string, myfunc>::iterator it = mymap.begin(); it != mymap.end(); ++it)
	{
		cout << "key:" << it->first << " " << "vaule:" << it->second << endl;
	}
}

void test03()
{
	map<int, string,myfunc>mymap;
	mymap.insert(pair<int, string>(3, "aaa"));

	mymap.insert(make_pair(6, "bbb"));

	mymap.insert(map<int, string>::value_type(2, "ccc"));

	mymap[4] = "ddd";
	printMap2(mymap);
	//根据键值从小到大排序
}

//注意：通过[]插入数据，如果访问的数据不存在，编译器会开辟键值，实值为空
void test04()
{
	map<int, string, myfunc>mymap;
	mymap.insert(pair<int, string>(3, "aaa"));

	mymap.insert(make_pair(6, "bbb"));

	mymap.insert(map<int, string>::value_type(2, "ccc"));

	mymap[4] = "ddd";
	printMap2(mymap);
	cout << "size:" << mymap.size() << endl;
	cout << mymap[100];
	printMap2(mymap);
	cout << "size:" << mymap.size() << endl;
}

/*
* map容器的查找操作
* find(elem)从前往后找，如果找到elem就返回第一elem的迭代器，如果找不到就返回mymap.end()
* count(elem)帮你数数map或者multimap容器中有多少个elem
* lower_bound(elem)帮你找到>=elem的最近元素的迭代器
* upper_bound(elem)帮你找到>elem的最近元素的迭代器
* equal_range(elem)帮你找到>=elem的最近两个元素对应的迭代器
*/

void test05()
{
	map<int, string>mymap;
	mymap[1] = "aaa";
	mymap[2] = "bbb";
	mymap[1] = "ccc";
	mymap[1] = "ddd";
	mymap[1] = "eee";
	map<int, string>::iterator it = mymap.find(2);
	if (it == mymap.end())
	{
		cout << "查找失败" << endl;
	}
	else
	{
		cout << "查找成功，查找结果为：" << endl;
		cout << "key:" << it->first << " " << "value:" << it->second << endl;
	}

	//剩下的那几个查找和set容器一样
	//来测试下equal_range
	//首先返回的是两个迭代器，来接的话就要用队组
	pair<map<int, string>::iterator, map<int, string>::iterator>ret = mymap.equal_range(3);
	//打印两个迭代器指针的内容
	if (ret.first != mymap.end())
	{
		cout << "key;" << ret.first->first << " " << "vaule:" << ret.first->second << endl;
	}

	if (ret.second != mymap.end())
	{
		cout << "key:" << ret.second->first << " " << "vaule:" << ret.second->second << endl;
	}
}
int main()
{
	test02();
	test03();
	test04();
	test05();
	

	return 0;
}