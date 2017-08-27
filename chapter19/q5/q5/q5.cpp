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
	vp.push_back(new A(1));//���1constructor
	vp.push_back(new A(2));//���2constructor
	//��ִ���������������ͷų�ָ��Ŀռ䣬˳�����1destructor��2destructor
	/*
	vector<A*>::iterator myptr = vp.begin();
	for (; myptr != vp.end(); ++myptr) {
		if (*myptr != NULL)
			delete *myptr;
	}
	*/
	vp.clear();//ע���ʱclear���������ͷų��ڴ�
	A a(4);//�Ⱥ����4constructor��4destructor
	return 0;
}