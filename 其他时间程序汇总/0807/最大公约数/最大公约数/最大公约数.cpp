#include <iostream>;
#include <algorithm>;
using namespace std;
int gys(int a, int b) {
	int x = min(a, b);
	int y = max(a, b);
	if (y%x == 0)
		return x;
	else
		return gys(x, y%x);
}
int main() {
	int X, Y;
	while (cin >> X >> Y)
		cout << gys(X, Y) << endl;
	return 0;
}