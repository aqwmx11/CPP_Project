#include <iostream>;
using namespace std;
int main() {
	int m, n = 0;
	cin >> m >> n;
	int a[30][30];
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++)
			cin >> a[i][j];
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			int state = 1;
			if (i - 1 >= 0) {
				if (a[i - 1][j]>a[i][j])
					state = 0;
			}
			if (j - 1 >= 0) {
				if (a[i][j-1]>a[i][j])
					state = 0;
			}
			if (i + 1 < m) {
				if (a[i + 1][j]>a[i][j])
					state = 0;
			}
			if (j + 1 < n) {
				if (a[i][j+1]>a[i][j])
					state = 0;
			}
			if (state == 1)
				cout << i << ' ' << j << endl;
		}
	}
	return 0;
}