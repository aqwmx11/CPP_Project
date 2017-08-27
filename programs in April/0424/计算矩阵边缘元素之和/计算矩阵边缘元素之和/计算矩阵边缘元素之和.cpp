#include <iostream>;
using namespace std;
int main() {
	int count = 0;
	cin >> count;
	for (int i = 0; i < count; i++) {
		int m, n;
		int sum = 0;
		int a[100][100];
		cin >> m >> n;
		for (int j = 0; j < m; j++) {
			for (int k = 0; k < n; k++)
				cin >> a[j][k];
		}
		for (int j = 0; j < m; j++) {
			for (int k = 0; k < n; k++) {
				if (j == 0 || j == m - 1 || k == 0 || k == n - 1)
					sum += a[j][k];
			}
		}
		cout << sum << endl;
		sum = 0;
		m = 0;
		n = 0;
		for (int j = 0; j < 100; j++) {
			for (int k = 0; k < 100; k++)
				a[j][k]=0;
		}
	}
	return 0;
}