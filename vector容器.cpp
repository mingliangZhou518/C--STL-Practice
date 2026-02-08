#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector> //用到什么容器就把什么容器的头文件给引进来
using namespace std;

/*
* 数据结构：连续存储空间
* 迭代器：随机迭代器
* vector容器动态增长原理：
* 1.当内存空间不够时，会申请一片更大的空间，把数据拷贝被进去后，再销毁原来的空间
* 2.另开辟的空间会比用户需求的要大一点
* 3.重新分配空间不是要销毁原来的空间吗，所以原来空间的迭代器也就失效了
* 
* 常用api:
* 1.构造
* 2.赋值操作
* 3.大小操作
* 4.数据存储
* 5.插入和删除
*/

/*
* 构造
* vector<T>vec;//无参模板类构造
* vector(v.begin(),v.end());//把这个迭代器间的数据给拷贝进来
* vector(n,elem);把n个elem给拷贝进来
* vector(const vector&vec);拷贝构造
*/

void printVector(const vector<int>& vec)
{
	for (vector<int>::const_iterator it = vec.begin(); it != vec.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;
}

//反向打印
void printRvector(const vector<int>& vec)
{
	for (vector<int>::const_reverse_iterator it = vec.rbegin(); it != vec.rend(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;
}

void test01()
{
	int arr[] = { 1,3,7,2,4,7,5,0 };
	vector <int>vec(arr, arr + sizeof(arr) / sizeof(int));
	printVector(vec);
	printRvector(vec);

	vector<int>vec2(6, 6);
	printVector(vec2);
}

/*
* vector容器常用的赋值操作
* assigin(n,elem);将n个elem赋值给自己
* assign(begin,end);将一个vec通过迭代器赋值给自己
* vector operator=(const vector<T>&vec2);通过重载=将另外一个vector容器的内容赋值给自己
* swap(const vector<T>vec);和另一个vector容器交换自己的内容
*/

void test02()
{
	vector<int>vec1;
	vec1.assign(10, 6);
	vector<int>vec2;
	vec2.push_back(1);
	vec2.push_back(2);
	vec2.push_back(3);
	printVector(vec1);
	printVector(vec2);

	cout << "======================" << endl;

	vec1.swap(vec2);
	printVector(vec1);
	printVector(vec2);
}

/*
* vector容器的大小操作
* size();//获取容器的大小
* capicity();//获取容器的容量
* empty();//判断容器是否为空
* resize(num);重新定义容器的大小，如果定义大了，则用默认值填充多出来的部分，如果定义小了，则删除多出来的部分
* resize(num,elem);重新定义容器的大小，如果定义大了，则用elem填充多出来的部分，如果定义笑了，则删除多出来的部分
* reserve(int len);容器预留len个元素的内存空间，预留位置不初始化，元素不可访问；主要作用是减少后续扩容时的拷贝次数，提高效率 
*/

void test03()
{

	//1.resize开辟空间并初始化
	//2.reserve开辟空间但并初始化
	vector<int>v2;
	v2.push_back(1);
	v2.push_back(2);
	v2.push_back(3);
	cout << "size:" << v2.size() << endl;
	v2.resize(5);
	cout << "size:" << v2.size() << endl;
	v2.push_back(6);
	printVector(v2);

	v2.reserve(20);
	v2.push_back(4);
	cout << "size:" << v2.size() << endl;
	printVector(v2);
	cout << "capacity:" << v2.capacity() << endl;
	//注意不能访问未初始化的空间
}

//reserve的作用:
//你想要一个很大空间来装内容，如果你不提前预留空间，每次动态存储到后面有数据挡道了，就会另开辟更大的空间来装数据
//就会导致系统很慢很慢
//如果你提前预留了一份很大的空间，后面就没有数据挡道了

void test04()
{
	vector<int>v3;
	v3.reserve(100100);
	int* p = NULL;
	int count=0;//记录编译器开辟了多少次空间
	for (int i = 0; i < 100100; i++)
	{
		v3.push_back(i);
		if (p != &v3[0])
		{
			p = &v3[0];
			count++;
		}
	
	}
	cout << "开辟空间的次数:" << count << endl;
}

//swap的使用：可以用来缩小空间
void test05()
{
	vector<int>v4;
	for (int i = 0; i < 10000; i++)
	{
		v4.push_back(i);

	}
	cout << "size:" << v4.size() << endl;
	cout << "capacity:" << v4.capacity() << endl;

	v4.resize(20);
	cout << "size:" << v4.size() << endl;
	cout << "capacity:" << v4.capacity() << endl;
	//显然，这里只缩小了size而没有缩小capacity，非常的浪费空间
	//我们先引入一个缩小的“办法”
	//拷贝构造
	vector<int>v5(v4);
	cout << "size:" << v5.size() << endl;
	cout << "capacity:" << v5.capacity() << endl;
	//说明引入一个新的内存来接这个内存的，系统会重新分配一个适合的容量
	//所以我们引进一个函数就是swap
	//为了更简介，直接使用了匿名构造,拷贝的指定对象直接匿名掉
	vector<int>(v4).swap(v4);
	cout << "size:" << v4.size() << endl;
	cout << "capacity:" << v4.capacity() << endl;
}

/*
* 数据存储操作
* at(int index)//返回索引index所指的数据，如果index越界，则会抛出out_of_range的异常
* operaror[]//返回index所指的数据，如果index越界，直接报错
* front()//返回容器的第一个元素
* back()//返回容器的最后一个元素
*/

void test06()
{
	vector<int>v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	printVector(v);
	cout << "front:" << v.front() << endl;
	cout << "back:" << v.back() << endl;

	v.at(0) = 100;
	v.at(2) = 300;
	for (int i = 0; i < v.size(); ++i)
	{
		cout << v[i] << " ";
	}
	cout << endl;
}

/*
* vector容器的插入和删除操作
* insert(const_iterator pos,int count,elem)//在vector容器的指定位置插入count个元素
* push_back(elem)//在容器的尾部插入elem
* pop_back()//删除最后一个元素
* erase(const_iterator begin,const_iterator end)//删除容器中从迭代器begin到end之间的所有元素
* erase(const_iterator pos)//删除容器指定位置的元素
* clear()//清除容器中所有的元素
*/

void test07()
{
	vector<int>v;
	for (int i = 0; i < 5; i++)
	{
		v.push_back(i + 1);
	}
	printVector(v);

	v.insert(v.begin() + 1, 2, 666);
	printVector(v);

	v.pop_back();
	printVector(v);

	v.erase(v.begin() + 2, v.end() - 2);
	printVector(v);

	v.erase(v.begin() + 1);
	printVector(v);

	v.clear();
	printVector(v);
}

int main()
{
	//test01();
	//test02();
	//test03();
	//test04();
	//test05();
	//test06();
	test07();
	return 0;
}