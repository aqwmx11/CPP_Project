#include <iostream>;
using namespace std;
int main() {
	int a = 0;
	cin >> a;
	if (a % 4 != 0) {
		cout << 'N' << endl;
	}
	else if (a % 100 == 0 && a % 400 != 0) {
		cout << 'N' << endl;
	}
	else if (a % 3200 == 0) {
		cout << 'N' << endl;
	}
	else {
		cout << 'Y' << endl;
	}
	return 0;
}