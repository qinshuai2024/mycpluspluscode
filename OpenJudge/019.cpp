#include <cstdlib>
#include <iostream>
using namespace std;
//int strlen(const char* s)
//{
//	int i = 0;
//	for (; s[i]; ++i);
//	return i;
//}
//void strcpy(char* d, const char* s)
//{
//	int i = 0;
//	for (i = 0; s[i]; ++i)
//		d[i] = s[i];
//	d[i] = 0;
//
//}
//int strcmp(const char* s1, const char* s2)
//{
//	for (int i = 0; s1[i] && s2[i]; ++i) {
//		if (s1[i] < s2[i])
//			return -1;
//		else if (s1[i] > s2[i])
//			return 1;
//	}
//	return 0;
//}
//void strcat(char* d, const char* s)
//{
//	int len = strlen(d);
//	strcpy(d + len, s);
//}
class MyString
{
	// 在此处补充你的代码
	char* p;
public:
	MyString(const char* ch)
	{
		p = new char[strlen(ch) + 1];
		strcpy(p, ch);
	}
	MyString()
	{
		p = new char[1];
		p[0] = '\0';
	}
	~MyString()
	{
		if (p)
			delete[]p;
	}
	MyString(const MyString& s)
	{
		p = new char[strlen(s.p) + 1];
		strcpy(p, s.p);
	}
	friend ostream& operator<<(ostream& out, MyString& s);
	MyString& operator+(MyString& s);
	bool operator<(const MyString& s);
	bool operator>(const MyString& s);
	bool operator==(const MyString& s);
	char& operator[](int i);
	MyString& operator+=(const char* ch);
	
	friend MyString& operator +(MyString& s, const char* ch);
	friend MyString& operator +(const char* ch,MyString& s);
	MyString& operator=(const char* ch);
	char* operator()(int begin, int len);
};
ostream& operator<<(ostream& out, MyString& s)
{
	out << s.p;
	return out;
}
MyString& MyString::operator+(MyString& s)
{
	int len = strlen(p) + strlen(s.p);
	MyString temp;
	temp.p = new char[len + 1];
	strcpy(temp.p, p);
	strcat(temp.p, s.p);
	return temp;
}
bool MyString::operator<(const MyString& s)
{
	if (strlen(p) < strlen(s.p))
		return true;
	return false;
}
bool MyString::operator>(const MyString& s)
{
	if (strlen(p) > strlen(s.p))
		return true;
	return false;
}
bool MyString::operator==(const MyString& s)
{
	if (strlen(p) == strlen(s.p))
		return true;
	return false; 
}
char& MyString::operator[](int i)
{
	return p[i];
}
MyString& MyString::operator+=(const char* ch)
{
	*this = *this + ch;
	return *this;
}
MyString& operator + (MyString& s, const char* ch)
{
	int len = strlen(ch) + strlen(s.p);
	MyString temp;
	temp.p = new char[len + 1];
	strcpy(temp.p, s.p);
	strcat(temp.p, ch);
	delete[]s.p;
	s.p = new char[len + 1];
	strcpy(s.p, temp.p);
	delete[]temp.p;
	return s;
}
MyString& operator + (const char* ch, MyString& s)
{
	MyString temp(ch);
	return  temp+s;
}
MyString& MyString::operator=(const char* ch)
{
	delete[]p;
	p = new char[strlen(ch) + 1];
	strcpy(p, ch);
	return *this;
}
char* MyString::operator()(int begin, int len)
{
	char* temp;
	temp = new char[len+1];
	int i,j;
	for (i = 0, j = begin; i < len; i++,j++)
	{
		temp[i] = p[j];
	}
	temp[i] = 0;
	return temp;
}
int CompareString(const void* e1, const void* e2)
{
	MyString* s1 = (MyString*)e1;
	MyString* s2 = (MyString*)e2;
	if (*s1 < *s2)
		return -1;
	else if (*s1 == *s2)
		return 0;
	else if (*s1 > *s2)
		return 1;
}
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
	qsort(SArray, 4, sizeof(MyString), CompareString);
	for (int i = 0; i < 4; i++)
		cout << SArray[i] << endl;
	//s1的从下标0开始长度为4的子串
	cout << s1(0, 4) << endl;
	//s1的从下标5开始长度为10的子串
	cout << s1(5, 10) << endl;
	return 0;
}