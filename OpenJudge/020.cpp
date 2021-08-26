#include <cstdlib>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
class MyString :public string
{

	// 在此处补充你的代码
public:
	MyString() :string() {}
	MyString(const char* s) :string(s) {} //给基类成员赋值
	MyString(const MyString& a) :string(a) {} //派生类给基类成员赋值
	MyString(const string& a) :string(a) {} /*对于+号 那些 基类含+号函数 默认对基类的字符串相加 
											之后的出来的值 再用类型转换函数
										  将 相加所返回的字符串再做类型转换函数 
										  转换为MYString类型*/
	friend ostream& operator<<(ostream& os, const string& a) //用派生类实参 输出基类成员
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
	//s1的从下标0开始长度为4的子串
	cout << s1(0, 4) << endl;
	//s1的从下标5开始长度为10的子串
	cout << s1(5, 10) << endl;
	return 0;
}