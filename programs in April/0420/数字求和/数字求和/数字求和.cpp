#include <iostream>;
using namespace std;
int main() {
	int a = 0;
	int sum = 0;
	cin >> a;
	int b[5];
	for (int i = 0; i < 5; i++) {
		cin >> b[i];
		if (b[i] < a) {
			sum = sum + b[i];
		}
	}
	cout << sum << endl;
}