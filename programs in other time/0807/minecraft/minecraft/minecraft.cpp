#include <iostream>;
using namespace std;
int main() {
	int C, N;
	cin >> C;
	for (int i = 0; i < C; i++) {
		cin >> N;
		int best = 999999;
		int temp = 0;
		for (int p = 1; p <= 10; p++) {
			for (int q = p; q <= 31; q++) {
				if (N % (p*q) == 0) {
					int r = N / p / q;
					temp = 2 * (p*q + p*r + q*r);
					if (temp < best)
						best = temp;
				}
			}
		}
		cout << best << endl;
	}
	return 0;
}