#include <iostream>
using namespace std;

class A {
public:
	int a;
	A(int k = 0) :a(k) {}
	void fun() {
		cout << "This is a test." << endl;
	}
};

int myfun(int a) {
	cout << "This is a test for myfun." << endl;
	return a;
}

void myfun2(const int& b) {// myfun2 takes a const reference to int b
	cout << "The test number is: " << b << endl;
}

int main() {
	//Create a function pointer for ordinary function
	int(*myptr)(int a);
	//Assign
	myptr = &myfun;
	//Call
	(*myptr)(2);//Parenthesis around *myptr is a must
	myptr(2);//This works too

	//Create a function pointer for function in a class
	void(A::*ptr)();//"A::" is a must, and must be placed before "*ptr"
	//Assign
	ptr = &A::fun;//"A::" is a must
	//Call
	A a;
	(a.*ptr)();//"a" is a must, this is the only way that works, a.ptr will be wrong

	//Create a function pointer for function which takes a const reference
	void(*myptr2)(const int& a);// const int& is a must
	//Assign
	myptr2 = &myfun2;
	//Call
	myptr2(5);

	return 0;

}