#include <iostream>;
#include <iomanip>;
using namespace std;
int main() {
	int m, n;
	int a[5][5];
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> a[i][j];
		}
	}
	cin >> n >> m;
	if (n < 0 || n > 4 || m < 0|| m > 4) {
		cout << "error" << endl;
	}
	else {
		int temp[5];
		for (int i = 0; i < 5; i++) {
			temp[i] = a[n][i];
			a[n][i] = a[m][i];
			a[m][i] = temp[i];
		}
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				cout << setw(4) << a[i][j];
			}
			cout << endl;
		}
	}
	return 0;
}