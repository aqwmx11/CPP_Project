#include <iostream>
#include <memory>
using namespace std;
class A {
	int v;
public:
	A(int n) :v(n) {
		cout << v << "constructed" << endl;
	}
	~A() {
		cout << v << "destructed" << endl;
	}
};
int main() {
	auto_ptr<A> ptr1(new A(3));//Êä³ö3constructed
	auto_ptr<A> ptr2;
	ptr2 = ptr1;
	ptr1.reset(NULL);
	cout << "step1" << endl;//Êä³östep1
	return 0;//Êä³ö3destructed
}