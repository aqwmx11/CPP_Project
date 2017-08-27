#include <iostream>
using namespace std;
class A {
public:
	A(){}
	virtual void func() {
		cout << "A::func" << endl;
	}
	~A(){}
	virtual void fund() {
		cout << "A::fund" << endl;
	}
};
class B :public A {
public:
	B() { func(); }
	void fun() {
		func();
	}
	~B() {
		fund();
	}
};
class C :public B {
public:
	C(){}
	void func() {
		cout << "C::func" << endl;
	}
	~C() {
		fund();
	}
	void fund() {
		cout << "C::fund" << endl;
	}
};
int main() {
	C c;//˳��ִ��A��B,C�Ĺ��캯������B�Ĺ��캯���������A::func
	return 0;//˳��ִ��C,B,A��������������C�����������������C::fund,��B�����������������A::fund
}