#include <iostream>;
using namespace std;
int main() {
	int n = 0;
	cin >> n;
	int x[120];
	int y[120];
	int max = 0;
	int state = 1;
	int max2 = -1;
	int maxnum = 0;
	for (int i = 0; i < 120; i++) {
		x[i] = 0;
		y[i] = 0;
	}
	for (int i = 0; i < n; i++)
		cin >> x[i] >> y[i];
	for (int i = 0; i < n; i++) {
		if (x[i] > max)
			max = x[i];
	}
	for (int p = 0; p < max; p++) {
		for (int i = 0; i < n; i++) {
			if (x[i] == p) {
				for (int j = 0; j < n; j++) {
					if (j != i&&x[j] >= x[i] && y[j] >= y[i]) {
						state = 0;
						break;
					}
				}
				if (state == 1)
					cout << '(' << x[i] << ',' << y[i] << "),";
			}
			state = 1;
		}
	}
	int max3 = -1;
	int maxnum2 = 0;
	for (int i = 0; i < n; i++) {
		if (x[i] == max&&y[i]>max3) {
			max3 = y[i];
			maxnum2 = i;
		}
	}
	cout << '(' << x[maxnum2] << ',' << y[maxnum2] << ')' << endl;
	return 0;
}