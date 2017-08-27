#include <iostream>;
#include <iomanip>;
#include <math.h>;
using namespace std;
int main() {
	int n = 0;
	cin >> n;
	double x[100];
	double y[100];
	double dis = 0;
	for (int i = 0; i < n; i++) {
		cin >> x[i] >> y[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j])*(y[i] - y[j]))>dis) {
				dis = sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j])*(y[i] - y[j]));
			}
		}
	}
	cout << fixed << setprecision(4) << dis << endl;
	return 0;
}