#include <iostream>;
using namespace std;
int main() {
	int N, K = 0;
	cin >> N >> K;
	int a[100];
	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < N; i++) {
		int larger = 0;
		int smaller = 0;
		for (int j = 0; j < N; j++) {
			if (a[j] > a[i]) {
				larger++;
			}
			else if (a[j] < a[i]) {
				smaller++;
			}
		}
		if (larger <= K - 1 && smaller <= N - K) {
			cout << a[i] << endl;
			break;
		}
	}
	return 0;
}