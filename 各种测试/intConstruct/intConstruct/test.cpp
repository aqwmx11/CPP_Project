#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	int i{};
	cout << i << endl;
	int k(2);
	cout << k << endl;
	double d{};
	cout << d << endl;
	int a[5]{ 1,2,3,4,5 };
	cout << *a << endl;
	cout << *(a+4) << endl;
	cout << setprecision(2) << 24.12555 << endl;//24
	cout << fixed << 24.125555 << endl;//24.13
	cout << 24.12555 << endl;//24.13
	cout << defaultfloat;
	cout<< 24.12555 << endl;//24
	cout << setprecision(0) << 24.12555 << endl;//24.1256
	cout << setprecision(2) << 32535 << endl;//32535, no effect
	cout << 24.12555 << endl;//24
	cout << setprecision(0);
	long long int b(4000000000);
	cout << b << endl;//4000000000
	int c(4000000000);
	cout << c << endl;//-294967296
	cout << setprecision(5)
		<< defaultfloat;
	cout << 555.555555 << ' '
		<< 444.444444e-10 << '\n';
	return 0;
}