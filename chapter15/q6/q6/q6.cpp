#include <iostream>
using namespace std;
class A {
public:
	virtual ~A() {
		cout << "destructor A" << endl;
	}
};
class B :public A {
public:
	~B() {
		cout << "desturctor B" << endl;
	}
};
int main() {
	A * pa;
	pa = new B;
	delete pa;
	return 0;
}