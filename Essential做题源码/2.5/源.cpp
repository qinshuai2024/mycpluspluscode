#include<iostream>
#include<vector>
using namespace std;

int Max(int x1, int x2)
{
	if (x1 >= x2)
		return 1;
	return 0;
}
int Max(float x1, float x2)
{
	if (x1  >= x2)
		return 1;
	return 0;
}
int Max(string x1, string x2)
{
	if (x1.length()  >= x2.length() )
		return 1;
	return 0;
}
int Max(const vector<int>& x1)
{
	//假设第一个是最大
	int imax = 0;
	//从第二个数开始遍历
	for (int i = 1; i < x1.size(); i++)
	{
		//如果比小标为imax的值大则将下标赋值给imax
		if (x1[imax] <= x1[i])
			imax = i;
	}
	return imax;
}
int Max(const vector<float>& x1)
{
	//假设第一个是最大
	int imax = 0;
	//从第二个数开始遍历
	for (int i = 1; i < x1.size(); i++)
	{
		//如果比小标为imax的值大则将下标赋值给imax
		if (x1[imax] <= x1[i])
			imax = i;
	}
	return imax;
}
int Max(const vector<string>& x1)
{
	//此时比较的是字符串的长度，与上个函数同理
	int imax = 0;
	//从第二个数开始遍历
	for (int i = 1; i < x1.size(); i++)
	{
		//如果比小标为imax的值大则将下标赋值给imax
		if (x1[imax].length() <= x1[i].length())
			imax = i;
	}
	return imax;
}
int Max(const int x1[], int size)
{
	int imax = 0;
	//从第二个数开始遍历
	for (int i = 1; i < size; i++)
	{
		//如果比小标为imax的值大则将下标赋值给imax
		if (x1[imax] <= x1[i])
			imax = i;
	}
	return imax;
}
int Max(const float x1[], int size)
{
	int imax = 0;
	//从第二个数开始遍历
	for (int i = 1; i < size; i++)
	{
		//如果比小标为imax的值大则将下标赋值给imax
		if (x1[imax] <= x1[i])
			imax = i;
	}
	return imax;
}
int Max(const string x1[], int size)
{
	int imax = 0;
	//从第二个数开始遍历
	for (int i = 1; i < size; i++)
	{
		//如果比小标为imax的值大则将下标赋值给imax
		if (x1[imax].length() <= x1[i].length())
			imax = i;
	}
	return imax;
}


int main()
{
	int x1 = 2, x2 = 5;
	float x3 = 4, x4 = 3.6;
	string x5 = "Iloveyou", x6 = "yes";
	float x77[7] = { 1,2,3,4.3,5.4,6.3,6.2 };
	vector<float> x7(x77,x77+7) ;
	string x88[3] = { "l","wq","adqw" };
	vector<string> x8(x88,x88+3);
	int x99[12] = { 1,32,5,5,32,23,52,32,23,34,42,32 };
	vector<int> x9(x99, x99 + 12);
	cout << "1." << Max(x1, x2) << endl
		<< "2." << Max(x3, x4) << endl
		<< "3." << Max(x5,x6) << endl
		<< "4." << Max(x9) << endl
		<< "5." << Max(x7) << endl
		<< "6." << Max(x8) << endl
		<< "7." << Max(x99,12) << endl
		<< "8." << Max(x77,7) << endl
		<< "9." << Max(x88,3) << endl;
	return 0;
}
