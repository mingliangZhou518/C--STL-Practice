#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<string>
#include<deque>
#include<ctime>//评委打分随机化
#include<algorithm>//引入算法
using namespace std;

/*
* 目的：
* 5个学生，10个评委，评委给学生分别打分，去除最高分和最低分，取平均值就是当前学生的分数
* 思路：
* 创建一个学生的类
* 学生放到vector容器当中
* 评委打的分数放到deque容器当中
* 对deque容器中的数据进行排序，删除首尾元素
* 对中间的元素取平均值
*/

class Student
{
public:
	int score;
	string name;
};

void printVector(vector<Student>& v)
{
	for (vector<Student>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << (*it).name << endl;
	}
}

void printScore(vector<Student>& v)
{
	for (vector<Student>::iterator it = v.begin(); it != v.end(); ++it)
	{
		cout << (*it).score << " ";
	}
	cout << endl;
}

void setStudentScore(vector<Student>& v)
{
	string allname = "ABCDE";
	for (int i = 0; i < allname.size(); i++)
	{
		Student stu;
		stu.name = "学生";
		stu.name += allname[i];
		v.push_back(stu);
	}
}

void printNameScore(vector<Student>& stu)
{
	for (vector<Student>::iterator it=stu.begin(); it != stu.end(); ++it)
	{
		cout << "name:" << (*it).name << " " << (*it).score << endl;
	}
}

//从大到小的排法要引入的回调函数
bool Compare(Student&s1,Student&s2)
{
	return s1.score > s2.score;
}

void range(vector<Student>& stu)
{
	sort(stu.begin(), stu.end(), Compare);
	cout << "分数从高到低依次为：";
	printScore(stu);

}

void getScore(vector<Student>& stu)
{
	srand((unsigned int)time(NULL));
	for (vector<Student>::iterator it = stu.begin(); it != stu.end(); ++it)
	{
		//多少个学生就塞多少次分数
		//排多少次顺序
		//头删尾删多少次
		//求多少次总分
		//求多少次平均值
		//赋值得到多少次分数
		deque<int>score;
		for (int i = 0; i < 10; i++)
		{
			
			int grade = rand() % 70 + 30;
			score.push_back(grade);
		}
		sort(score.begin(), score.end());
		score.pop_front();
		score.pop_back();
		int sum = 0;
		for (deque<int>::iterator it2 = score.begin(); it2 != score.end(); ++it2)
		{
			sum += (*it2);
		}
		int average = sum / score.size();
		(*it).score = average;
	}
}

void test01()
{
	vector<Student>vstu;
	setStudentScore(vstu);
	getScore(vstu);
	printNameScore(vstu);
	range(vstu);

}
int main()
{
	test01();

	return 0;
}