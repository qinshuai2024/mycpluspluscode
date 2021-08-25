#include<iostream>
#include<vector>
using namespace std;


inline bool InputCorrect(int size)
{
	if (size < 0 || size>1e5)
	{
		cout << "所需元素个数太大，无法执行！\n";
		return false;
	}
	return true;
}
//存放Pentagonal数列
void CreatElem(vector<int>& pent, int size)
{
	if (!InputCorrect(size))
		return;
	for (int i = 0; i < size; i++)
	{
		pent[i] = (i+1) * (3 * (i+1) - 1) / 2;
	}
}
void PrintVector(vector<int>& pent)
{
	for (int i = 0; i < pent.size(); i++)
	{
		cout << pent[i];
		cout << " ";
	}
}
int main()
{
	int size;
	cout << "请输入想要的元素个数：\n";
	cin >> size;
	vector<int> pent(size);
	CreatElem(pent, size);
	PrintVector(pent);
	return 0;
}