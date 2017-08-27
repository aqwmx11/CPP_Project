#include <iostream>;
#include <iomanip>;
#include <string>;
using namespace std;
int main() {
	int n = 0;
	int a = 0;
	int b = 0;
	int c = 0;
	int d = 0;
	int sum = 0;
	int temp = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		if (temp < 19) {
			a++;
		}
		else if (temp < 36 && temp > 18) {
			b++;
		}
		else if (temp < 61 && temp> 35) {
			c++;
		}
		else {
			d++;
		}
	}
	sum = a + b + c + d;
	double a1 = (double)a / sum * 100;
	double b1 = (double)b / sum * 100;
	double c1 = (double)c / sum * 100;
	double d1 = (double)d / sum * 100;
	cout << "1-18: " << fixed<< setprecision(2) << a1 << "%"<<endl;
	cout << "19-35: " << fixed << setprecision(2) << b1 << "%" << endl;
	cout << "36-60: " << fixed << setprecision(2) << c1 << "%" << endl;
	cout << "60-: " << fixed << setprecision(2) << d1 << "%" << endl;
	return 0;
}