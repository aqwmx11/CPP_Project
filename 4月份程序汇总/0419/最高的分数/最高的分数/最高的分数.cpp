#include <iostream>
using namespace std;
int main() {
	int n = 0;
	int a[100];
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int temp = 0;
	for (int i = 0; i < n; i++) {
		if (temp < a[i]) {
			temp = a[i];
		}
	}
	cout << temp;
	return 0;
}