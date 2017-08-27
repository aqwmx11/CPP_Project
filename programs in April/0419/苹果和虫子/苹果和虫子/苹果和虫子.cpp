#include <iostream>;
using namespace std;
int main() {
	int n, x, y = 0;
	cin >> n >> x >> y;
	int remain, eat = 0;
	if (y > x*n) {
		remain = 0;
	}
	else {
		if (y%x == 0) {
			eat = y / x;
			remain = n - eat;
		}
		else {
			eat = y / x + 1;
			remain = n - eat;
		}
	}
	cout << remain;
}