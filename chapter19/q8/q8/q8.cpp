#include <iostream>
#include <vector>
using namespace std;
template<class T>
void PrintAll(const T& c) {
	T::const_iterator i;
	for (i = c.begin(); i != c.end(); ++i)
		(*i)->Print();//注意这个地方*i必须用括号括起，否则运行不通过
}
class A {
protected:
	int nVal;
public:
	A(int i) :nVal(i) {}
	virtual void Print() {
		cout << "A::Print: " << nVal << endl;
	}
};
class B :public A {
public:
	B(int i):A(i){}
	void Print() {
		cout << "B::Print: " << nVal << endl;
	}
};
int main() {
	vector< A * > v;
	v.push_back(new A(1));
	v.push_back(new B(2));
	v.push_back(new B(3));
	PrintAll(v);
	return 0;
}