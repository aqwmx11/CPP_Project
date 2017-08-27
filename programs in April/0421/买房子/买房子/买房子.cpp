#include <iostream>;
using namespace std;
int main() {
	int N, K = 0;
	while (cin >> N >> K) {
		double price = 200;
		int salary = 0;
		int failure = 0;
		double rate = (double)K / 100;
		for (int i = 1; i < 21; i++) {
			salary = salary + N;
			if (salary >= price) {
				cout << i << endl;
				break;
			}
			else {
				failure++;
			}
			price = price*(1 + rate);
		}
		if (failure == 20) {
			cout << "Impossible" << endl;
		}
	}
	return 0;
}