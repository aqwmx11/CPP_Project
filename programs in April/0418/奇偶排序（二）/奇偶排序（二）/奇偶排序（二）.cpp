#include <iostream>;
using namespace std;
int main() {
	int a[10], b[10];
	int oddnum = 0;
	for (int p = 0; p < 10; p++) {
		cin >> a[p];
	}
	for (int i = 1; i < 10; i++) {
		for (int j = 0; j < 10 - i; j++) {
			if (a[j] > a[j + 1]) {
				int temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
	for (int p = 0; p < 10; p++) {
		bool odd = a[p] % 2 == 1;
		if (odd) {
			oddnum++;
		}
	}
	int i = 0;
	int j = oddnum;
	for (int p = 0; p < 10; p++) {
		bool odd = a[p] % 2 == 1;
		if (odd) {
			b[i] = a[p];
			i++;
		}
		else {
			b[j] = a[p];
			j++;
		}
	}
	for (int p = 0; p < 10; p++) {
		cout << b[p] << ' ';
	}
	return 0;
}