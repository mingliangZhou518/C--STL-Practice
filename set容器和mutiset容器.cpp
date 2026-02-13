#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<set>//multiset也是这个头文件
#include<algorithm>
using namespace std;

/*
* set容器是关联式容器，容器有自己的规则，容器的元素既是键值也是实值
* set容器和multset容器的区别，multiset容器允许有相同的元素
* 数据结构：平衡二叉树
* 树形结构有查询很快的优势因为可以根节点和节点之间有比大小的  
* 迭代器：双向迭代器
* 常用的api：
*/

//测试迭代器
void test01()
{
	
	set<int>::iterator it;
	it++;
	it--;
	//it+1 error
	//双向迭代器
}

/*
* 构造函数
* set<T>st;//无参构造
* multiset<T>mst;//无参构造
* set(const set<T>&st)//拷贝构造
* 
* 赋值操作
* set operator=(const set<T>&st);//重载等号运算符
* swap(st);//交换容器内容
* 
* 大小操作
* size();//返回容器中元素数量
* empty();//判断容器是否为空
* 
* 插入和删除操作
* insert(elem);//向容器插入elem
* clear();//清除容器中的所有元素
* erase(pos);//删除容器中对应索引的元素
* erase(elem);//删除容器中的所有elem
* erase(begin,end);//删除容器中索引之间[begin,end)的所有内容
* 
*/


void printSet(set<int>& st)
{
	for (set<int>::iterator it = st.begin(); it != st.end(); ++it)
	{
		cout << *it << " ";

	}
	cout << endl;
}

void test02()
{
	set<int>st;
	st.insert(3);
	st.insert(5);
	st.insert(1);
	st.insert(7);
	st.insert(6);
	st.insert(8);
	printSet(st);
}

/*
* 改版set容器的规则，从大到小打印
* 
*/
struct myfunc
{
	//修改容器规则时必须告诉编译器不改变容器变量，不改变函数本身的结构
	bool operator()(const int&v1,const int&v2)const
	{
		return v1 > v2;
	}
};



void printSet2(set<int, myfunc>&st)
{
	for (set<int, myfunc>::iterator it = st.begin();it!=st.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;
}

void test03()
{
	//加入包含重载()的结构体类型
	set<int, myfunc>st;
	st.insert(3);
	st.insert(5);
	st.insert(1);
	st.insert(7);
	st.insert(6);
	st.insert(8);
	printSet2(st);

}

//set容器不允许有两个相同的元素
void test04()
{
	set<int, myfunc>st;
	st.insert(2);
	st.insert(4);
	st.insert(6);
	st.insert(1);
	st.insert(9);
	printSet2(st);

	//如果你强行插入一个相同的元素
	//编译器不会报错，但会把相同的元素给你忽略掉
	st.insert(6);
	printSet2(st);

	//insert返回的是队组
	pair<set<int, myfunc>::iterator, bool>mp = st.insert(6);
	if (mp.second)
	{
		cout << "插入成功" << endl;
	}

	else
	{
		cout << "插入失败" << endl;
	}

	st.erase(4);
	st.erase(st.begin());
	printSet2(st);
}

//通过算法进行遍历和排序

void printVal(int val)
{
	cout << val << " ";
}
void test05()
{
	multiset<int>st;
	st.insert(3);
	st.insert(5);
	st.insert(1);
	st.insert(7);
	st.insert(6);
	st.insert(8);
	st.insert(8);
	//遍历算法
	for_each(st.begin(), st.end(), printVal);
	cout << endl;

	//不能通过排序算法来排序关联式容器元素
	//sort(st.begin(),st.end());
}

/*
* 查找操作
* find(elem);找容器中和elem相等的元素，找到就但会他的迭代器，找不到就返回st.end()
* lower_bound(elem);返回第一个>=elem的第一个元素的迭代器、
* upper_bound(elem);返回第一个>elem的第一个元素的迭代器
* equal_range(keyelem);返回容器中elem和keyelem相等的上下限的两个迭代器
*/

void test06()
{
	set<int>st;
	st.insert(2);
	st.insert(3);
	st.insert(5);
	st.insert(1);
	st.insert(7);
	st.insert(4);
	//因为查找返回的是指针，所以我们用指针来接
	set<int>::iterator it = st.find(4);
	if (it == st.end())
	{
		cout << "查找失败" << endl;

	}
	else
	{
		cout << "查找成功" << *it<<endl;
	}

	set<int>::iterator it2 = st.lower_bound(4);
	if (it2 == st.end())
	{
		cout << "查找失败" << endl;
	}

	else
	{
		cout << "查找成功：" << *it2 << endl;
	}

	set<int>::iterator it3 = st.upper_bound(4);
	if (it3 == st.end())
	{
		cout << "查找失败" << endl;
	}

	else
	{
		cout << "查找成功：" << *it3 << endl;
	}

	//不是要返回两个迭代器吗，所以用队组来接
	//返回set容器中大于等于该值的两个靠前的迭代器
	pair<set<int>::iterator, set<int>::iterator>mp = st.equal_range(3);
	cout << *mp.first << endl;
	cout << *mp.second << endl;
}

void test07()
{
	multiset<int>s;
	s.insert(3);
	s.insert(3);
	s.insert(3);
	s.insert(6);
	s.insert(1);
	s.insert(2);
	for_each(s.begin(), s.end(), printVal);
	cout << endl;
	cout << "3的数量有：" << s.count(3) << endl;
}

//储存对象
//set容器还是会按照自己的规则对数字内容进行排序
//set容器自带的是对基础的数据比大小
//储存对象并且对象中有数字，那么就要把对应的结构体进行重写
class Maker
{
public:
	Maker(string name, int age)
	{
		this->name = name;
		this->age = age;
	}

	Maker()
	{

	}

public:
	string name;
	int age;
};

struct classFunc
{
	bool operator()(const Maker& m1, const Maker& m2)const
	{
		return m1.age > m2.age;
	}
};

void test08()
{
	set<Maker,classFunc>s;
	s.insert(Maker("aaa", 18));
	s.insert(Maker("bbb",20 ));
	s.insert(Maker("ccc", 19));
	s.insert(Maker("ddd", 25));
	s.insert(Maker("eee", 17));
	for (set<Maker,classFunc>::iterator it = s.begin(); it != s.end(); ++it)
	{
		cout << "name:" << it->name << " " << "age:" << it->age << endl;
	}
}


int main()
{
	//test01();
	test02();
	//按照自身规则进行排序，从小到大
	test03();
	test04();
	test05();
	test06();
	test07();
	test08();

	return 0;
}