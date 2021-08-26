//#include <iostream>
//using namespace std;
//class B {
//private:
//	int nBVal;
//public:
//	void Print()
//	{
//		cout << "nBVal=" << nBVal << endl;
//	}
//	void Fun()
//	{
//		cout << "B::Fun" << endl;
//	}
//	B(int n) { nBVal = n; }
//};
//class D :public B {
//private:
//	int nDVal;
//public:
//	D(int n) :B(3 * n), nDVal(n) {}
//	void Fun()
//	{
//		cout << "D::Fun" << endl;
//	}
//	void Print()
//	{
//		B::Print();
//		cout << "nDVal=" << nDVal << endl;
//	}
//};
//
//// 在此处补充你的代码
//int main() {
//	B* pb; D* pd;
//	D d(4);//B(3 * n)，d里面的B的nBval值为12 
//	d.Fun();//输出D::Fun
//	pb = new B(2); pd = new D(8);
//	pb->Fun(); //输出B::Fun
//	pd->Fun(); //输出D::Fun
//	pb->Print(); //nBVal=2
//	pd->Print();//nBVal=24
//	pb = &d; 
//	pb->Fun();
//	pb->Print();
//	return 0;
//}