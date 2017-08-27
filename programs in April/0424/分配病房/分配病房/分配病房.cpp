#include <iostream>;
#include <iomanip>;
using namespace std;
int main() {
	int m = 0;
	double a;
	cin >> m >> a;
	int id[100], id2[100];
	int count = 0;
	int temp = 0;
	double state[100], state2[100];
	for (int i = 0; i < m; i++) {
		cin >> id[i] >> state[i];
		if (state[i] >= a)
			count++;
	}
	if (count == 0)
		cout << "None." << endl;
	else {
		for (int i = 0; i < count; i++) {
			for (int j = temp; j < m; j++) {
				if (state[j] >= a) {
					temp = j + 1;
					id2[i] = id[j];
					state2[i] = state[j];
					break;
				}
			}
		}
		int maxnumber = 0;
		for (int i = 0; i < count; i++) {
			for (int j = 0; j < count; j++) {
				if (state2[j] > state2[maxnumber])
					maxnumber = j;
			}
			cout << setfill('0') << setw(3) << id2[maxnumber] << ' ' << fixed<<setprecision(1)<<state2[maxnumber] << endl;
			state2[maxnumber] = 0;
			maxnumber = 0;
		}
	}
	return 0;
}