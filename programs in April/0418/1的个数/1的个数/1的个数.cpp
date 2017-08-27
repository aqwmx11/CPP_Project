#include <iostream>;
using namespace std;
int main() {
	int k = 0;
	cin >> k;
	for (int i = 1; i < k + 1; i++) {
		int num = 0;
		int count = 0;
		cin >> num;
		while (num > 0) {
			count = count + num % 2;
			num = num / 2;
		}
		cout << count << endl;
	}
	return 0;
}