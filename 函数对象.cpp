#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;
/*
* 类中通过operator重载了()，通过这个类实例化的对象叫做函数对象(仿函数)
* 一元仿函数是operator()有一个参数，二元仿函数是operator()有两个参数
* 可以作为算法的策略
*/

/*
* 函数对象可以有自己的状态
* 普通函数没有类型，函数对象有类型
* 函数对象有可能比普通函数的执行效率更高
*/

/*
* 谓词是指普通函数或者重载()的operator的返回值为bool类型的类或结构体实例化的对象(仿函数)
* 谓词可以作为一个判断式
* operator接受一个谓词就是一元谓词，接受两个参数就是二元谓词
*/

struct myfunc//函数对象有类型
{
public:
	myfunc()
	{
		int n = 0;
	}

	void operator()()//函数对象有自己的状态
	{
		cout << "hello" << endl;
	}
public:
	int n;
};
void printVal(int val)
{
	cout << val << " ";
}

void test01()
{
	vector<int>vec;
	vec.push_back(4);
	vec.push_back(2);
	vec.push_back(6);
	vec.push_back(0);
	vec.push_back(8);
	sort(vec.begin(), vec.end());
	for_each(vec.begin(), vec.end(),printVal);
	cout << endl;
	cout << "========================" << endl;
	//通过仿函数从大到小排序
	//后面装的是匿名对象
	sort(vec.begin(), vec.end(), greater<int>());//内建函数对象，已经有了现成的模板类
	//通过仿函数遍历
	for_each(vec.begin(), vec.end(), [](int val) {cout << val << " "; });
	cout << endl;
	//[]表示是函数，（）内代装的是参数，{}内装的是函数内容
	//整体表示的是无名函数
}

void test02()
{
	plus<int>myplus;
	//引用头文件functional,引入仿函数模板类，实例化成对象就可以当仿函数用了
	cout << myplus(10, 20) << endl;
}

/*
* 内建函数
* template <class T> T plus<T>
* template <class T> T minus<T>
* template <class T> T multiplies<T>
* template <class T> T divides<T>
* template <class T> bool equal_to<T>
* template <class T> bool no_equal_to<T>
* template <class T> bool greater<T>
* template <class T> bool greater_equal<T>
* template <class T> bool less<T>
* template <class T> bool less_equal<T>
* 
*/
int main()
{
	test01();
	test02();

	return 0;
}