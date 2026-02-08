#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<deque>
using namespace std;

/*
* deque容器：双端队列
* 数据结构：表面上看起来像是一块连续的空间，其实是由很多个块空间通过中控器连接起来
* 迭代器：随机迭代器
* 常用的api（接口）（中间人）：
* 1.构造
* 2.赋值
* 3.大小
* 4.双端的插入和删除
* 5.插入和删除
* 
*/

void printDeque(const deque<int>& deq)
{
	for (deque<int>::const_iterator it = deq.begin(); it != deq.end(); ++it)
	{
		cout << *it << " ";

	}
	cout << endl;
}

void test01()
{
	deque<int>::iterator it;
	it++;
	it--;
	it + 2;
	//证明了deque是随机迭代器
}

/*
* 构造
* deque<T> deq;//无参构造
* deque<T>(const& deque<T>deq)//拷贝构造
* deque<T>(begin,end)//迭代器拷贝内容进来
* deque<T>(n,elem)//把n个elem存储进来
*/

void test02()
{
	int arr[] = { 2,3,5,2,1,4,0,9,8,6 };
	deque<int>deq(arr, arr + sizeof(arr) / sizeof(int));
	printDeque(deq);
	deque<int>deq2(6, 6);
	printDeque(deq2);
}


/*
* deque的赋值操作：
* assign(n,elem);//把n个elem给赋值进去
* assign(begin,end)//把另一个容器通过迭代器把内容给复制赋值过来
* operator=(const deque<T>&deq);重载等号运算符
* swap(deq);与deq容器的内容互换
*/

void test03()
{

	int arr[] = { 2,3,5,2,1,4,0,9,8,6 };
	deque<int>deq1(arr, arr + sizeof(arr) / sizeof(int));
	printDeque(deq1);

	deque<int>deq2(deq1.begin(), deq1.end());
	deq2.push_back(100);
	printDeque(deq2);
	cout << "===========================" << endl;

	deq1.swap(deq2);
	printDeque(deq1);
	printDeque(deq2);
}

/*
* 大小操作
* size();//读取大小
* empty();//判断是否为空,空就返回非0
* resize(num)//重新定义num大小的空间
* resize(num,elem)//重新定义num大小的空间，多出来的默认初始化elem
*/

void test04()
{
	deque<int>deq;

	cout << "size:" << deq.size() << endl;

	if (deq.empty())
	{
		cout << "空" << endl;
	}

	for (int i = 0; i < 10; i++)
	{
		deq.push_back(i + 1);
	}

	deq.resize(20, 6);
	printDeque(deq);
}

/*
* 双端的插入和删除
* push_back(elem)//尾插
* push_front(elem)//头插
* pop_back()//尾删
* pop_front()//头删
* 
* //获取元素
* front();//返回头元素
* back();//返回尾元素
* at(index);//获取索引元素,会抛出异常
* operator[];//获取索引元素，但不会抛出异常
*/

void test05()
{
	deque<int>deq;

	for (int i = 0; i < 10; i++)
	{
		deq.push_back(i + 1);
	}
	printDeque(deq);

	deq[2] = 200;
	deq.at(3) = 300;
	printDeque(deq);

	cout << "front:" << deq.front() << endl;
	cout << "back:" << deq.back() << endl;
}

/*
* 插入操作：
* insert(index,elem);//索引位置插入elem
* insert(index,n,elem);//索引位置插入n个elem
* insert(index,begin,end);//索引位置通过迭代器插入另一个容器的数据
*/

void test06()
{
	deque<int>deq;
	for (int i = 1; i < 6; i++)
	{
		deq.push_back(i * 10);
	}
	printDeque(deq);
	deq.insert(deq.begin() + 1, 6, 6);
	printDeque(deq);
	cout << "======================" << endl;

	deque<int>deq2;
	for (int i = 0; i < 8; i++)
	{
		deq2.push_back(i + 1);
	}
	printDeque(deq2);

	deq2.insert(deq2.begin() + 4, deq.begin(), deq.end());
	printDeque(deq2);
}

/*
* 删除操作：
* erase(index)//一个一个的删除
* erase(beginn(),end())//一片一片的删除
* clear()//一口气全部删了
*/

void test07()
{
	deque<int>deq;
	for (int i = 0; i < 10; i++)
	{
		deq.push_back(i + 1);
	}
	printDeque(deq);
	deq.erase(deq.begin()+3);
	printDeque(deq);
	deq.erase(deq.end()-1);//end返回的是最后一个元素后面的那个指针
	printDeque(deq);
	deq.erase(deq.begin() + 1, deq.end() - 2);//删掉的是从前面开始到后一个的前面
	printDeque(deq);
	deque<int>::iterator it = deq.erase(deq.begin() + 1, deq.end() - 2);
	cout << "返回的数是：" << *it << endl;//返回的是end所指向的
	deq.clear();
	printDeque(deq);
}

int main()
{
	test02();
	test03();
	test04();
	test05();
	test06();
	test07();

	return 0;
}