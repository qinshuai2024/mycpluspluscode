#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;
class Complex {
private:
    double r, i;
public:
    void Print() {
        cout << r << "+" << i << "i" << endl;
    }
    Complex(const char x[])
    {
        r = x[0]-48 ;
        i = x[2]-48 ;
    }
    Complex()
    {
        r = 0;
        i = 0;
    }

};
int main() {
    Complex a;
    a = "3+4i"; a.Print();
    a = "5+6i"; a.Print();
    return 0;
}