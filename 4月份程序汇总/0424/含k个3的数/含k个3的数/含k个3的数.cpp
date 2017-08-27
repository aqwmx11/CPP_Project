#include <iostream>;
using namespace std;
int main() {
	int m, k = 0;
	cin >> m >> k;
	int state = 1;
	if (m % 19 != 0)
		state = 0;
	int sum = 0;
	int num = 0;
	while (m > 0) {
		num = m % 10;
		if (num == 3)
			sum++;
		m = m / 10;
	}
	if (sum != k)
		state = 0;
	if (state == 1)
		cout << "YES" << endl;
	else if (state == 0)
		cout << "NO" << endl;
	return 0;
}