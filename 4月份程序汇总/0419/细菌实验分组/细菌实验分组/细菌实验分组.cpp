#include <iostream>;
using namespace std;
int main() {
	int n, begin, end, num = 0;
	int differ = 0;
	cin >> n;
	float a[100];
	int b[100];
	for (int i = 0; i < n; i++) {
		cin >> b[i] >> begin >> end;
		a[i] = (float)end / begin;
	}
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < n - i; j++) {
			if (a[j] > a[j + 1]) {
				float temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
				int temp2 = b[j];
				b[j] = b[j + 1];
				b[j + 1] = temp2;
			}
		}
	}
	for (int i = 0; i < n - 1; i++) {
		int tdiffer = a[i + 1] - a[i];
		if (tdiffer > differ) {
			differ = tdiffer;
			num = i;
		}
	}
	cout << n - num - 1 << endl;
	for (int i = num + 1; i < n; i++) {
		cout << b[i] << endl;
	}
	cout << num + 1 << endl;
	for (int i = 0; i < num + 1; i++) {
		cout << b[i] << endl;
	}
	return 0;
}