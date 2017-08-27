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
	C c;//顺次执行A，B,C的构造函数，在B的构造函数处，输出A::func
	return 0;//顺次执行C,B,A的析构函数，在C的析构函数处，输出C::fund,在B的析构函数处，输出A::fund
}