#include <iostream>;
using namespace std;
int main() {
	int n, k = 0;
	int a[1000];
	int state = 0;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (a[i] + a[j] == k) {
				state = 1;
				break;
			}
		}
	}
	if (state == 1) {
		cout << "yes" << endl;
	}
	else {
		cout << "no" << endl;
	}
	return 0;
}