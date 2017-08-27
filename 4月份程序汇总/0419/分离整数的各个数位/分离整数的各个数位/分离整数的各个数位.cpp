#include <iostream>;
using namespace std;
int main() {
	int n = 0;
	cin >> n;
	int a[3];
	for (int i = 1; i < 4; i++) {
		a[3 - i] = n % 10;
		n = n /10;
	}
	for (int i = 0; i < 3; i++) {
		cout << a[i] << endl;
	}
	return 0;
}