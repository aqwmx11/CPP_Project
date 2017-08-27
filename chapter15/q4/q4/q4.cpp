#include <iostream>
using namespace std;
class A {
public:
	A(){}
	virtual void func() {
		cout << "A::func" << endl;
	}
	virtual void fund() {
		cout << "A::fund" << endl;
	}
	void fun() {
		cout << "A::fun" << endl;
	}
};
class B :public A {
public:
	B() {
		func();
	}
	void fun() {
		func();
	}
};
class C :public B {
public:
	C(){}
	void func() {
		cout << "C::func" << endl;
	}
	void fund() {
		cout << "C::fund" << endl;
	}
};
int main() {
	A* pa = new B();//顺次执行A和B的构造函数，并在执行B的构造函数时输出A::func
	pa->fun();//由于fun不是虚函数，此处没有多态，执行A类的fun函数，输出A::fun
	B* pb = new C();//顺次执行A,B,C的构造函数，并在执行B的构造函数时输出A::func
	pb->fun();//fun不是虚函数，因此执行B的fun函数，但func是虚函数构成多态，因此执行C类的func函数，输出C::func
	return 0;
}