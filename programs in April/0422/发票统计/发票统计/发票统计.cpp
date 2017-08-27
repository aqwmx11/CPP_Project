#include <iostream>;
#include <iomanip>;
using namespace std;
int main() {
	int id[3];
	float money[100];
	float sum[3];
	float sumA = 0;
	float sumB = 0;
	float sumC = 0;
	char kind[100];
	for (int i = 0; i < 3; i++) {
		sum[i] = 0;
	}
	for (int i = 0; i < 3; i++) {
		int n = 0;
		cin >> id[i] >> n;
		for (int j = 0; j < n; j++) {
			cin >> kind[j] >> money[j];
			sum[i] += money[j];
			if (kind[j] == 'A') {
				sumA += money[j];
			}
			else if (kind[j] == 'B') {
				sumB += money[j];
			}
			else if (kind[j] == 'C') {
				sumC += money[j];
			}
		}
	}
	for (int i = 0; i < 3; i++) {
		if (id[i] == 1) {
			cout << "1 " << fixed << setprecision(2) << sum[i] << endl;
		}
	}
	for (int i = 0; i < 3; i++) {
		if (id[i] == 2) {
			cout << "2 " << fixed << setprecision(2) << sum[i] << endl;
		}
	}
	for (int i = 0; i < 3; i++) {
		if (id[i] == 3) {
			cout << "3 " << fixed << setprecision(2) << sum[i] << endl;
		}
	}
	cout << "A " << fixed << setprecision(2) << sumA << endl;
	cout << "B " << fixed << setprecision(2) << sumB << endl;
	cout << "C " << fixed << setprecision(2) << sumC << endl;
}