#include <iostream>;
using namespace std;
int main() {
	int m, n = 0;
	cin >> n >> m;
	int a[100];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= m; i++) {
		for (int j = n - 1; j >= 0; j--) {
			a[j + 1] = a[j];
		}
		a[0] = a[n];
		a[n] = 0;
	}
	for (int i = 0; i < n; i++) {
		cout << a[i] << ' ';
	}
	cout << endl;
}