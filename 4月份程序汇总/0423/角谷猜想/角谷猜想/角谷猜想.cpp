#include <iostream>;
using namespace std;
void jiaogu(int a) {
	if (a == 1)
		cout << "End" << endl;
	else if (a % 2 == 1) {
		cout << a << "*3+1=" << a*3+1 << endl;
		a = a * 3 + 1;
		jiaogu(a);
	}
	else if (a % 2 == 0) {
		cout << a << "/2=" << a / 2 << endl;
		a = a / 2;
		jiaogu(a);
	}
}
int main() {
	int n = 0;
	cin >> n;
	jiaogu(n);
	return 0;
}