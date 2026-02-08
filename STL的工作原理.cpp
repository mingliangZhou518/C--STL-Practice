#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;

template<class T>
class myArray
{
public:
	//保护原生指针，给指针取别名
	typedef T* iterator;//iterator意思是迭代器
	//容器
	myArray()
	{
		mCapcity = 10;
		mSize = 0;
		p = new T[mCapcity];

		for (int i = 0; i < mCapcity; i++)
		{
			p[i] = i + 1;
			mSize++;
		}
	}

	//迭代器
	T* begin()
	{
		return p;
	}

	T* end()
	{
		return p + mSize;
	}

private:
	T* p;
	int mCapcity;
	int mSize;
};


//算法
template<class T>
void myPrint(T*begin,T*end)
{
	for (; begin != end; ++begin)
	{
		cout << *begin << " ";
	}
	cout << endl;
}

void test01()
{
	//模板类访问其中的元素写法
	myArray<int> arr;
	//获取容器提供的开始位置迭代器
	myArray<int>::iterator begin = arr.begin();
	//获取容器提供的结束位置迭代器
	myArray<int>::iterator end = arr.end();
	myPrint(begin, end);
	
}

int main()
{
	test01();

	return 0;
}