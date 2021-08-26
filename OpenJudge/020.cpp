#include <cstdlib>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
class MyString :public string
{

	// �ڴ˴�������Ĵ���
public:
	MyString() :string() {}
	MyString(const char* s) :string(s) {} //�������Ա��ֵ
	MyString(const MyString& a) :string(a) {} //������������Ա��ֵ
	MyString(const string& a) :string(a) {} /*����+�� ��Щ ���ຬ+�ź��� Ĭ�϶Ի�����ַ������ 
											֮��ĳ�����ֵ ��������ת������
										  �� ��������ص��ַ�����������ת������ 
										  ת��ΪMYString����*/
	friend ostream& operator<<(ostream& os, const string& a) //��������ʵ�� ��������Ա
	{
		os << a;
		return os;
	}

	MyString operator()(int start, int length)
	{
		MyString ret(substr(start, length));
		return ret;
	}

};


int main()
{
	MyString s1("abcd-"), s2, s3("efgh-"), s4(s1);
	MyString SArray[4] = { "big","me","about","take" };
	cout << "1. " << s1 << s2 << s3 << s4 << endl;
	s4 = s3;
	s3 = s1 + s3;
	cout << "2. " << s1 << endl;
	cout << "3. " << s2 << endl;
	cout << "4. " << s3 << endl;
	cout << "5. " << s4 << endl;
	cout << "6. " << s1[2] << endl;
	s2 = s1;
	s1 = "ijkl-";
	s1[2] = 'A';
	cout << "7. " << s2 << endl;
	cout << "8. " << s1 << endl;
	s1 += "mnop";
	cout << "9. " << s1 << endl;
	s4 = "qrst-" + s2;
	cout << "10. " << s4 << endl;
	s1 = s2 + s4 + " uvw " + "xyz";
	cout << "11. " << s1 << endl;
	sort(SArray, SArray + 4);
	for (int i = 0; i < 4; i++)
		cout << SArray[i] << endl;
	//s1�Ĵ��±�0��ʼ����Ϊ4���Ӵ�
	cout << s1(0, 4) << endl;
	//s1�Ĵ��±�5��ʼ����Ϊ10���Ӵ�
	cout << s1(5, 10) << endl;
	return 0;
}