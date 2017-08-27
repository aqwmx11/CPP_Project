#include <iostream>
using namespace std;
class A {
public:
	virtual ~A() {
		cout << "DestructA" << endl;
	}
};
class B :public A {
public:
	virtual ~B() {
		cout << "DestructB" << endl;
	}
};
class C :public B {
public:
	~C() {
		cout << "DestructC" << endl;
	}
};
int main() {
	A* pa = new C;
	delete pa;//虚析构函数会导致顺次执行C，B，A的虚构函数，输出DestructC,DestructB,DestructA
	A a;//只有A的虚构函数会执行，输出DestructA
	return 0;
}