#include <iostream>
#include <vector>
using namespace std;
class A {
private:
	int nId;
public:
	A(int n) {
		nId = n;
		cout << nId << "constructor" << endl;
	}
	~A() {
		cout << nId << "destructor" << endl;
	}
};
int main() {
	vector<A*> vp;
	vp.push_back(new A(1));//输出1constructor
	vp.push_back(new A(2));//输出2constructor
	//在执行下面的语句后才能释放出指针的空间，顺次输出1destructor和2destructor
	/*
	vector<A*>::iterator myptr = vp.begin();
	for (; myptr != vp.end(); ++myptr) {
		if (*myptr != NULL)
			delete *myptr;
	}
	*/
	vp.clear();//注意此时clear函数不会释放出内存
	A a(4);//先后输出4constructor和4destructor
	return 0;
}