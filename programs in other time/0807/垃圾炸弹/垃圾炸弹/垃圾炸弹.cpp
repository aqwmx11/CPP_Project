#include <iostream>;
using namespace std;
struct node {
	int x, y, num;
	node(int a = 0, int b = 0, int c = 0) {
		x = a; y = b; num = c;
	}
};
node a[20];
int main() {
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		int d,n;
		int sum = 0;
		int nnum = 0;
		int best = 0;
		cin >> d>>n;
		for (int i = 0; i < n; i++) 
			cin >> a[i].x >> a[i].y >> a[i].num;
		for (int p = 0; p <= 1024; p++) {
			for (int q = 0; q <= 1024; q++) {
				sum = 0;
				for (int k = 0; k < n; k++) {
					if (a[k].x <= p + d&&a[k].x >= p - d&&a[k].y <= q + d&&a[k].y >= q - d)
						sum += a[k].num;
				}
				if (sum == best)
					nnum++;
				else if (sum > best) {
					nnum = 1;
					best = sum;
				}
			}
		}
		cout << nnum << " " << best << endl;
	}
	return 0;
}
