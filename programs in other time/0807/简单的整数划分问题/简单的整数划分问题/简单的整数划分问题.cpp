#include <iostream>;
using namespace std;
int split(int n, int m) {
	if (n < 1 || m < 1) return 0;
	if (n == 1 || m == 1) return 1;
	if (n < m) return split(n, n);
	if (n == m) return (split(n, m - 1) + 1);
	if (n > m) return (split(n, m - 1) + split((n - m), m));
}
int main() {
	int N;
	while (cin >> N)
		cout << split(N, N) << endl;
	return 0;
}