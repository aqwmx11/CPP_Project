#include <iostream>;
using namespace std;
int main() {
	int n = 0;
	int a[100];
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = n - 1; i >= 0; i--) {
		cout << a[i] << ' ';
	}
	return 0;
}