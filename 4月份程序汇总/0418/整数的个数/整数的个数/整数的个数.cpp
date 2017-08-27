#include <iostream>;
using namespace std;
int main() {
	int k = 0;
	int a[100];
	int n1 = 0;
	int n5 = 0;
	int n10 = 0;
	cin >> k;
	for (int i = 0; i < k; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < k; i++) {
		if (a[i] == 1) {
			n1++;
		}
		else if (a[i] == 5) {
			n5++;
		}
		else if (a[i] == 10) {
			n10++;
		}
	}
	cout << n1 << endl;
	cout << n5 << endl;
	cout << n10 << endl;
	return 0;
}