#include <iostream>;
using namespace std;
int main() {
	int a, b, result = 0;
	char ope;
	cin >> a >> b >> ope;
	if (ope == '+') {
		result = a + b;
		cout << result << endl;
	}
	else if (ope == '-') {
		result = a - b;
		cout << result << endl;
	}
	else if (ope == '*') {
		result = a * b; 
		cout << result << endl;
	}
	else if (ope == '/'&&b != 0) {
		result = a / b;
		cout << result << endl;
	}
	else if (ope == '/'&&b == 0) {
		cout << "Divided by zero!" << endl;
	}
	else {
		cout << "Invalid operator!" << endl;
	}
	return 0;
}