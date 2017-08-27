#include <iostream>;
using namespace std;
int main() {
	int n = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int mile = 0;
		cin >> mile;
		double walk = (double)mile / 1.2;
		double bike = (double)mile / 3.0 + 50;
		if (walk < bike) {
			cout << "Walk" << endl;
		}
		else if (bike < walk) {
			cout << "Bike" << endl;
		}
		else {
			cout << "All" << endl;
		}
	}
	return 0;
}