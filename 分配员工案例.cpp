#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<map>
#include<list>
#include<set>
#include<vector>
#include<ctime>
using namespace std;
#define _DEVELOP_DEPARTMENT 1
#define _SALES_DEPARTMENT 2
#define _FINANCIAL_DEPARTMENT 3

/*
* 新三王的调用讲究
* list:双向链表，任意位置增删快
* 迭代器只能 ++/--，无 []，增删用 push/insert
* 不能写 it+1，不要用 [] 访问
* set/multiset:元素即键，自动排序
* 迭代器只能 ++/--，不能改元素，查用 find
* 自定义排序要加 const，键不能改
* map/multimap:键值对，按键自动排序
* 迭代器访问 it->first/second，map 有 []
* multimap 无 []，map [] 会自动创键
*/

/*
* 目的：
* 公司招来5个员工，随机分配到三个部门，分配完毕后打印部门名和员工信息
* 
* 思路：
* 抽象员工
* 把员工放到vector容器当中
* 再把员工分配到multimap容器当中
* 
* 流程：
* 创建员工
* 分配员工
* 打印员工
*/

class Worker
{

public:
	string name;
	int age;
	int salary;
};

void createWorker(vector<Worker>&vWorker)
{
	
	string setName = "ABCDEF";
	for (int i = 0; i < 5; i++)
	{
		Worker worker;
		worker.name = "员工";
		worker.name += setName[i];
		worker.age = rand() % 30 + 10;
		worker.salary = rand() % 200000 + 300000;
		vWorker.push_back(worker);
	}
}

void WorkerByGroup(vector<Worker>& vWorker, multimap<int, Worker>& mWorker)
{
	for (vector<Worker>::iterator it = vWorker.begin(); it != vWorker.end(); ++it)
	{
		int id = rand() % 3 + 1;
		mWorker.insert(make_pair(id, *it));
	}
}

void myGroup(multimap<int, Worker>& mWorker, int id)
{
	multimap<int, Worker>::iterator it = mWorker.find(id);
	int count = mWorker.count(id);
	int index = 0;

	//最重要的是我这里要做一个人数限制，让multimap刚好只能打印完对应id的value
	for (; it != mWorker.end()&&index<count; ++it,++index)
	{
		cout << "姓名：" << it->second.name << " " << "年龄：" << it->second.age << " " << "薪水：" << it->second.salary << endl;
	}
		
	
}

void printWorker(multimap<int, Worker>& mWorker)
{
	cout << "技术部门的人员如下:" << endl;
	myGroup(mWorker, _DEVELOP_DEPARTMENT);
	cout << "销售部门的人员如下:" << endl;
	myGroup(mWorker, _SALES_DEPARTMENT);
	cout << "财务部门的人员如下:" << endl;
	myGroup(mWorker, _FINANCIAL_DEPARTMENT);
}

void test01()
{
	srand((unsigned int)time(NULL));
	vector<Worker>vWorker;
	multimap<int, Worker>mWorker;
	createWorker(vWorker);
	WorkerByGroup(vWorker, mWorker);
	printWorker(mWorker);
}
int main()
{
	test01();

	return 0;
}