#include <iostream>;
using namespace std;
int main() {
	int*pn;
	char c = 0x65;
	pn = (int*)&c;
	int n = *pn;
	cout << n << endl; //�����һ���ǳ���ֵ�ֵ
	return 0;
}