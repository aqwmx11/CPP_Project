#include <iostream>;
using namespace std;
int main() {
	int a, b, c = 0;
	char str1, str2;
	cin >> a >> str1 >> b >> str2 >> c;
	if (a + b == c)
		cout << '+' << endl;
	else if (a - b == c)
		cout << '-' << endl;
	else if (a*b == c)
		cout << '*' << endl;
	else if (a / b == c)
		cout << '/' << endl;
	else if (a%b == c)
		cout << '%' << endl;
	else
		cout << "error" << endl;
	return 0;
}