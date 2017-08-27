#include <iostream>;
using namespace std;
int main() {
	int h, r = 0;
	double pi = 3.14159;
	int n = 0;
	double v = 0;
	cin >> h >> r;
	v = (double)pi*r*r*h;
	n = 20000 / v + 1;
	cout << n;
	return 0;
}