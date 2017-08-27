#include <iostream>;
using namespace std;
int main() {
	int n = 0;
	cin >> n;
	for (int i = 10; i <= n; i++) {
		int shiwei = i / 10;
		int gewei = i - 10 *shiwei;
		if (i % (shiwei + gewei) == 0) {
			cout << i << endl;
		}
	}
	return 0;
}