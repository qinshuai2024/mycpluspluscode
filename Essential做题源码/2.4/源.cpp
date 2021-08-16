#include<iostream>
#include<vector>
using namespace std;

inline bool InputCorrect(int size)
{
	if (size < 0 || size>1e5)
	{
		cout << "����Ԫ�ظ���̫���޷�ִ�У�\n";
		return false;
	}
	return true;
}
//���Pentagonal����
int CreatElem(int size)
{
	if (!InputCorrect(size))
		return -1;
	int elem = size  * (3 * size  - 1) / 2;
	return elem;
}
void PrintVector(const vector<int>& pent)
{
	for (int i = 0; i < pent.size(); i++)
	{
		cout << pent[i];
		cout << " ";
	}
}
const vector<int>* Pent(int size)
{
	static vector<int> pent;
	if (!InputCorrect(size))
		return NULL;
	for (int i = pent.size()+1; i <= size; i++)
	{
		pent.push_back(CreatElem(i));
	}
	return &pent;
}
int FindElem(const vector<int>& pent,int x)
{
	Pent(x + 1);

	return pent[x];
}
int main()
{
	int size;
	cout << "��������Ҫ��Ԫ�ظ�����\n";
	cin >> size;
	const vector<int>* sur= Pent(size);
	PrintVector(*sur);
	cout << endl;
	cout << "��������Ҫ��Ԫ���±꣺\n";
	int x;
	cin >> x;
	cout<<FindElem(*sur,x);
	return 0;
}