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

    //调用函数直接返回一个类对象
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
        //没有从类类型转换到内置类型的转换函数，但是可以是类到类，内置到类。
        a.GetObj() = A(n);
        cout << a.val << endl;
    }
    return 0;
}