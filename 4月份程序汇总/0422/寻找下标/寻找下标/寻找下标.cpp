#include <iostream>;
using namespace std;
int main() {
	int n = 0;
	int state = 0;
	cin >> n;
	int x[100];
	for (int i = 0; i < n; i++) {
		cin >> x[i];
	}
	for (int i = 0; i < n; i++) {
		if (x[i] == i) {
			cout << i << endl;
			state = 1;
			break;
		}
	}
	if (state == 0) {
		cout << 'N' << endl;
	}
	return 0;
}