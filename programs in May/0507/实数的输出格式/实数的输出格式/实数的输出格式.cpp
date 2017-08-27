#include <iostream>;
#include <iomanip>;
using namespace std;
int main() {
	double a;
	cin >> a;
	cout << fixed << setprecision(5) << a<<endl;
	cout.unsetf(ios::fixed);
	cout.setf(ios::scientific);
	cout.precision(7);
	cout << a << endl;
	return 0;
}