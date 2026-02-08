#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;




/*
* string容器
* 数据结构：连续的存储空间，用一个char*指向这个空间
* 迭代器：随机访问迭代器
* 常用的api：
* 
* string的常用api
* 1.构造
* 2.基本赋值
* 3.拼接
* 4.插入和删除
* 5.比较
* 6.指针和string类型的转换
* 7.存取字符
* 8.查找和替换
* 9.子串

* 常用的api中的注意：
*/

/*
* string构造函数
* string ();创建一个空的字符串,例如string str
* string(const string&str)用一个string对象去初始化另一个string对象
* string(const char*s)使用字符串s初始化
* string(int n,char c)使用n个字符c初始化
*/

void test01()
{
	string::iterator it;
	it++;
	it--;
	it + 2;
}

void test02()
{
	//string是模板类，但是它内部有内部处理，所以不许要<>说明模板数据类型
	string s1;
	string s2(10, 'a');
	string s3(s2);
	string s4("hello");
}

/*
* 基本赋值操作
* string& operator=(const char*s);char*类型的字符串赋值给当前字符
* string& operator=(const string&s);把字符串s赋值给当前的字符串
* string& operator=(char c);字符赋值给当前的字符串
* string& assign(const char*s);把字符串s赋值给当前的字符
* string& assign(const char*s,int n);把字符串的前n个字母赋值给当前字符串
* string& assign(string& s);把字符串s赋值给当前字符串
* string& assign(int n,char c);用n个字符c赋值给当前字符串
* string& assign(const string&s,int start,int n);将s从start开始的n个字符赋值给当前字符串
*/

void test03()
{
	string s1;
	s1 = "hello world";
	cout << s1 << endl;

	string s2;
	s2.assign("hello mygirl");
	s2.assign(s1);
	cout << s2 << endl;

	string s3;
	s3.assign("hello world", 3, 5);
	cout << s3 << endl;
}

/*
* 存取字符操作
* char& operator[](int n)//通过[]方式获取字符
* char& at(int n)//通过at获取字符
*/

void test04()
{
	string s = "hello world";
	for (int i = 0; i < s.size(); i++)
	{
		cout << s[i] << " ";
	}
	cout << endl;

	for (int i = 0; i < s.size(); i++)
	{
		cout << s.at(i) << " ";
	}
	cout << endl;

	try
	{
		cout << s.at(100) << endl;
	}

	catch (out_of_range& ex)
	{
		cout << ex.what() << endl;
		cout << "访问越界" << endl;
	}

	//[]访问和at访问的区别
	//[]访问，如果越界，不抛异常直接挂
	//at()访问，如果越界，抛完异常再挂，会内部throw
}

/*
* 拼接操作
* string& operator+=(const char*s);重载+=运算符
* string& operator+=(char c);重载+=运算符
* string& operator+=(const string&s)重载+=运算符
* string& append(const char*s);把s指向的字符串添加到后面
* string& append(const char*s,int n)把s指向的字符串的前n个添加到后面
* string& append(const string&s)把字符串添加到后面
* string& append(const string&s,int pos,int n)把字符串从索引pos开始的n位添加到后面
* string& append(int n,char c)把n个字符c添加到后面
*/

void test05()
{
	string s1 = "aaa";
	s1 += "bbb";
	s1 += 'c';
	cout << s1 << endl;

	s1.append("dddddd", 4);
	cout << s1 << endl;
}

/*
* 查找和替换
* int find(const char*s,int pos=0) const//查找s第一次出现的位置，从pos开始查找
* int find(const char*s,int pos,int n) const//查找从pos开始的前n个字符的第一次位置
* int find(const string s,int pos=0) const//查找s出现的第一个位置，从pos开始
* int find(const char c,int n=0) const//查找字符c第一次出现位置
* int rfind(const char*s,int pos=npos) const//查找s最后一次出现位置，从pos开始
* int rfind(const char*s,int pos=npos,int n) const//从pos开始查找s前n个字符最后一次位置
* int rfind(const string&s,int pos=npos) const//查找s最后一次位置，从pos开始
* int rfind(const char c,int pos=0) const//查找字符c最后一次出现位置
* string& replace(int pos,int n,string& s) const//替换从pos开始n个字符为字符串s
* string& replace(int pos,int n,char* s) const//替换从pos开始的n个字符为字符串s
*/

void test06()
{
	string s = "abcdefgd";
	int index1 = s.find('d');//3
	cout << index1 << endl;
	int index2 = s.rfind('d');//7
	cout << index2 << endl;
	int index3 = s.find("cde");//2
	cout << index3<<endl;
	string s2 = s.replace(3, 2, "AAAA");
	cout << s2 << endl;
}

/*
* 比较操作
* compare函数在>时返回1，在<时返回-1，在==时返回0
* int compare(const char*s)//与字符串s进行比较
* int compare(const string&s)//与字符串s进行比较
*/

void test07()
{
	string s1 = "hello";
	string s2 = "hello";
	char s[] = "world";
	if (s1.compare(s2) == 0)
	{
		cout << "s1=s2" << endl;
	}
	if (s2.compare(s)==0)
	{
		cout << "s2=s" << endl;
	}
	else
	{
		cout << "s2!=s" << endl;
	}
}

/*
* 子串
* string substr(int pos=0,int n=npos)//返回由pos开始的n个字符组成的字符串
* //配合查找截取字符串
*/

void test08()
{
	string s = "hello world";
	int pos = s.find('o');
	string s2 = s.substr(0, pos);
	cout << s2 << endl;
	string s3 = s.substr(pos + 1);
	cout << s3 << endl;
}

/*
* 插入和删除操作
* string& insert(int pos,const char*s);//插入字符串
* string& insert(int pos,const string& s)//插入字符串
* string& insert(int pos,int n,char c)//在指定位置插入n个字符
* string& erase(int pos,int n=npos);//删除从指定位置开始的n个字符
*/

void test09()
{
	string s = "aaaa";
	s.insert(3, "BBB");
	cout << s << endl;
	s.insert(3, "MMM");
	cout << s << endl;
	s.erase(4, 2);
	cout << s << endl;
}

/*
* string和c-style的转化
* 
*/

void test10()

{
	//指针类型转化为string类型
	const char* s = "hello world";
	string s2 = string(s);
	cout << s2 << endl;

	//string类型转化为指针类型
	const char* s3 = s2.c_str();
	cout << s3 << endl;
}


/*
* 修改字符串之后（给字符串重新进行了空间分配），再用[]和at()获取字符引用会出错
*/

void test11()
{
	string s = "abcdefg";
	char& a = s[0];
	char& b = s[1];
	a = '1';
	b = '2';
	cout << s << endl;
	//获取此时字符串的地址
	cout << "原字符串的空间地址:"<<(int*)s.c_str() << endl;

	s = "fawfawfawhcsdvsdvfvdfv";
	cout << "现字符串的空间地址:" << (int*)s.c_str() << endl;
	//原空间被释放了，但是a还是原空间字符的引用，非法操作直接给你荡了
	/*a = '3';*/
	
}

//用迭代器遍历字符串
void test12()
{
	string s = "dawheufhaufh";
	for (string::iterator it = s.begin(); it != s.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;
}


//用迭代器进行反向遍历
void test13()
{
	string s = "whefaevaiefh";
	for (string::reverse_iterator it = s.rbegin(); it != s.rend(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;
}

int main()
{
	/*test03();
	test04();
	test05();
	test06();
	test07();
	test08();
	test09();
	test10();*/
	test11();
	test12();
	test13();
	return 0;
}