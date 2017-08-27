#include <iostream>;
using namespace std;
int main() {
	int L, M = 0;
	int a[10001];
	int sum = 0;
	cin >> L >> M;
	for (int i = 0; i <= L; i++) {
		a[i] = 1;
	}
	for (int p = 1; p <= M; p++) {
		int start = 0;
		int end = 0;
		cin >> start >> end;
		for (int j = start; j <= end; j++) {
			a[j] = 0;
		}
	}
	for (int i = 0; i <= L; i++) {
		if (a[i] == 1) {
			sum++;
		}
	}
	cout << sum << endl;
	return 0;
};