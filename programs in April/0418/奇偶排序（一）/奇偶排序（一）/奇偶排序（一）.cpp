#include <iostream>;
using namespace std;
int main() {
	int a[10], b[10];
	int i = 0;
	int j = 9;
	for (int p = 0; p < 10; p++) {
		cin >> a[p];
	}
	for (int r = 0; r < 10; r++) {
		bool odd = a[r] % 2 == 1;
		if (odd) {
			b[i] = a[r];
			i++;
		}
		else {
			b[j] = a[r];
			j--;
		}
	}
	for (int m = 1; m < i; m++) {
		for (int n = 0; n < i - m; n++) {
			if (b[n] > b[n + 1]) {
				int temp = b[n];
				b[n] = b[n + 1];
				b[n+1] = temp;
			}
		}
	}
	for (int m = 1; m < 10 - i; m++) {
		for (int n = i; n < 10 - m; n++) {
			if (b[n] > b[n + 1]) {
				int temp2 = b[n];
				b[n] = b[n + 1];
				b[n + 1] = temp2;
			}
		}
	}
	for (int p = 0; p < 10; p++) {
		cout << b[p] << ' ';
	}
	return 0;
}