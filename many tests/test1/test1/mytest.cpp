#include <iostream>;
using namespace std;
int main() {
	int*pn;
	char c = 0x65;
	pn = (int*)&c;
	int n = *pn;
	cout << n << endl; //会输出一个非常奇怪的值
	return 0;
}