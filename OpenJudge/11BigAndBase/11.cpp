#include <iostream>
#include <string>
using namespace std;
class Base {
public:
    int k;
    Base(int n) :k(n) { }
};
class Big
{
public:
    int v;
    Base b;

    friend Base;
    Big(int i) :b(i)
    {
        v = i;
    }

};
int main()
{
    int n;
    while (cin >> n) {
        Big a1(n);
        Big a2 = a1;
        cout << a1.v << "," << a1.b.k << endl;
        cout << a2.v << "," << a2.b.k << endl;
    }
}