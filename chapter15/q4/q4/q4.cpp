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
	A* pa = new B();//˳��ִ��A��B�Ĺ��캯��������ִ��B�Ĺ��캯��ʱ���A::func
	pa->fun();//����fun�����麯�����˴�û�ж�̬��ִ��A���fun���������A::fun
	B* pb = new C();//˳��ִ��A,B,C�Ĺ��캯��������ִ��B�Ĺ��캯��ʱ���A::func
	pb->fun();//fun�����麯�������ִ��B��fun��������func���麯�����ɶ�̬�����ִ��C���func���������C::func
	return 0;
}