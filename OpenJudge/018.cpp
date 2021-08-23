#include <iostream> 
#include <cstring> 
#include <cstdlib> 
#include <cstdio> 
using namespace std;
const int MAX = 110;
class CHugeInt {
private:
	char buf[220];//�̶�һ��220λ��С�����飬���ڽ��ж���
public:
	void reverse(char* p)//���洢���ݵ�����������������������ʽ����ӵ�λ���λ���е�ԭ��
	{
		int len = strlen(p);
		int i = 0, j = len - 1;
		while (i < j)
		{
			swap(p[i], p[j]);
			++i;
			--j;
		}
	}
	CHugeInt(char* p)
	{
		memset(buf, 0, sizeof(buf));//��buf��ʼ��
		strcpy(buf, p);
		reverse(buf);
	}
	CHugeInt(int n)
	{
		memset(buf, 0, sizeof(buf));
		sprintf(buf, "%d", n);
		reverse(buf);
	}
	CHugeInt operator+(int n)
	{
		return *this + CHugeInt(n);//����ֱ�����ú���д�����������	
	}
	CHugeInt operator+(const CHugeInt& n) const
	{
		CHugeInt tmp(0);
		int carry = 0;//��λ
		for (int i = 0; i < 210; i++)
		{
			char c1 = buf[i];
			char c2 = n.buf[i];
			if (c1 == 0 && c2 == 0 && carry == 0)
				break;
			if (c1 == 0)
				c1 = '0';
			if (c2 == 0)
				c2 = '0';
			int k = c1 - '0' + c2 - '0' + carry;
			if (k >= 10)//��Ӵ���10���λ
			{
				carry = 1;//��λλ��1
				tmp.buf[i] = k - 10 + '0';
			}
			else
			{
				carry = 0;
				tmp.buf[i] = k + '0';
			}
		}
		return tmp;
	}
	friend CHugeInt operator+(int n, const CHugeInt& h)
	{
		return h + n;
	}
	friend ostream& operator<<(ostream& o, const CHugeInt& h)//������������
	{
		int len = strlen(h.buf);
		for (int i = len - 1; i >= 0; --i)
			cout << h.buf[i];
		return o;
	}
	CHugeInt& operator++()
	{
		*this = *this + 1;
		return *this;
	}
	CHugeInt operator++(int)
	{
		CHugeInt tmp(*this);
		*this = *this + 1;
		return tmp;
	}
	CHugeInt& operator+=(int n)
	{
		*this = *this + n;
		return *this;
	}
};
int  main()
{
	char s[210];
	int n;

	while (cin >> s >> n) {
		CHugeInt a(s);
		CHugeInt b(n);

		cout << a + b << endl;
		cout << n + a << endl;
		cout << a + n << endl;
		b += n;
		cout << ++b << endl;
		cout << b++ << endl;
		cout << b << endl;
	}
	return 0;
}


//int main()
//{
//	char arr[1] = { '2' };
//	int x = arr[0] - '0';
//	cout << x << endl;
//	arr[0] = 1 + '0';
//	cout << arr[0] << endl;
//	return 0;
//}