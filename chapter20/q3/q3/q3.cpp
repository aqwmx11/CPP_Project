#include <iostream>
#include <memory>
using namespace std;
class A {
	int v;
public:
	A(int n) :v(n) { cout << v << "constructed" << endl; }
	~A() {
		cout << v << "destructed" << endl;
	}
};
int main() {
	A* p = new A(2);
	auto_ptr<A> ptr(p);
	p = NULL;
	cout << "step1" << endl;
	ptr.reset(NULL);
	p = new A(3);
	ptr.reset(p);
	p = NULL;
	cout << "step2" << endl;
	p = ptr.release();
	delete p;
	cout << "before return" << endl;
	return 0;
}