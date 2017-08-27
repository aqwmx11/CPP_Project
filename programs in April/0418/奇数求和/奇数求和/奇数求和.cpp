#include <iostream>;
using namespace std;
int main() {
	int m = 0;
	int n = 0;
	int sum = 0;
	cin >> m;
	cin >> n;
	bool evenm = m % 2 == 0;
	if (evenm) {
		m = m + 1;
	}
	bool evenn = n % 2 == 0;
	if (evenn) {
		n = n - 1;
	}
	for (int a = m; a < n + 1; a = a + 2) {
		sum = sum + a;
	}
	cout << sum << endl;
	return 0;
}