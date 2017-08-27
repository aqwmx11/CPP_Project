#include <iostream>;
using namespace std;
int main() {
	char a[20] = "Hello";
	char b[20] = "world";
	for (int i = 0; b[i] != 0; i++) {
		a[5 + i] = b[i];
	}
	cout << a << endl;
	return 0;
}