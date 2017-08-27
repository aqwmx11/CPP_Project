#include <iostream>
using namespace std;

class A {//Our base class
public:
	int a;
	A(int k=0) :a(k){}
	A& operator =(A x) {//We define assignment operator in class A
		a = 2 * x.a;
		return *this;
	}
	void showInfo() {
		cout << "The variable a in this object is: " << a << endl;
	}
};

class B :public A {//Our derived class
public:
	int aa;
	B(int j = 0,int k=1):A(j),aa(k){}
	void showInfo() {
		cout << "The variable a in this object is: " << a << endl;
		cout << "The variable aa in this object is: " << aa << endl;
	}
};

int main() {
	A mya(1);
	A mya2(2);
	cout << "Before assigning..." << endl;
	mya.showInfo();//1
	mya2.showInfo();//2
	cout << "After assigning..." << endl;
	mya = mya2;
	mya.showInfo();//4
	mya2.showInfo();//2
	cout << "Here is a test for derived class" << endl;
	B myb(1, 2);
	B myb2(3, 9);
	cout << "Before assigning..." << endl;
	myb.showInfo();//a=1,aa=2
	myb2.showInfo();//a=3,aa=9
	cout << "After assigning..." << endl;
	myb = myb2;
	myb.showInfo();//a=6,aa=9, which indicates that the assignment operator we defined in class A take effects here!
	myb2.showInfo();//a=3,aa=9
	return 0;
}
