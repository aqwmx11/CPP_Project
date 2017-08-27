#include <iostream>;
using namespace std;
int main() {
	int N = 0;
	int a[15000];
	while (cin >> N&&N > 0 && N <= 15000) {
		for (int i = 0; i < N; i++) {
			cin >> a[i];
		}
		for (int i = 1; i <= N - 1; i++) {
			for (int j = 0; j < N - i; j++) {
				if (a[j] > a[j + 1]) {
					int temp = a[j];
					a[j] = a[j + 1];
					a[j + 1] = temp;
				}
			}
		}
		if (N % 2 == 1) {
			cout << a[(N - 1) / 2] << endl;
		}
		else {
			cout << (a[N / 2] + a[N / 2 - 1]) / 2 << endl;
		}
	}
	return 0;
}