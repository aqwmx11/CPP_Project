#include <iostream>;
using namespace std;
int main() {
	int a[6];
	int differ = 0;
	for (int i = 0; i < 6; i++) {
		cin >> a[i];
	}
	int maxodd = 0;
	int mineven = 100;
	for (int i = 0; i < 6; i++) {
		if (a[i] % 2 == 1) {
			if (a[i] > maxodd) {
				maxodd = a[i];
			}
		}
		else {
			if (a[i] < mineven) {
				mineven = a[i];
			}
		}
	}
	if (maxodd > mineven) {
		differ = maxodd - mineven;
	}
	else {
		differ = mineven - maxodd;
	}
	cout << differ;
	return 0;
}