#include <iostream>
using namespace std;
class A {
public:
    int val;

    A(int i)
    {
        val = i;
    }
    A() :val(123) {}

    //���ú���ֱ�ӷ���һ�������
    A& GetObj()
    {
        return *this;
    }
};
int main()
{
    int m, n;
    A a;
    cout << a.val << endl;
    while (cin >> m >> n) {
        a.GetObj() = m;
        cout << a.val << endl;
        //û�д�������ת�����������͵�ת�����������ǿ������ൽ�࣬���õ��ࡣ
        a.GetObj() = A(n);
        cout << a.val << endl;
    }
    return 0;
}