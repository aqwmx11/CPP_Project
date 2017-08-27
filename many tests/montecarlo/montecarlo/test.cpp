#include <iostream>
#include <stdlib.h>
using namespace std;

double min(double a, double b) {
	if (a < b)
		return a;
	else
		return b;
}

double max(double a, double b) {
	if (a < b)
		return b;
	else
		return a;
}

int main() {
	double a, b;
	while (cin >> a >> b) {
		int count = 0;
		for (int i = 1; i <= 10000; ++i) {
			double u1 = rand() / double(RAND_MAX);
			double u2 = rand() / double(RAND_MAX);
			double k1 = min(u1, u2);
			double k2 = max(u1, u2);
			double l1 = k1;
			double l2 = k2 - k1;
			if (l1 <= a &&l2 <= b)
				count += 1;
		}
		cout << double(count)/10000 << endl;
	}
	return 0;	
}