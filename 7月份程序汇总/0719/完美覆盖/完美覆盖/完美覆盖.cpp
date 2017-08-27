#include <iostream>;
using namespace std;
int answer(int n) {
	if (n == 0)
		return 1;
	if (n == 2)
		return 3;
	if (n > 2 && n % 2 == 0)
		return 4 * answer(n - 2) - answer(n - 4);
	if (n % 2 != 0)
		return 0;
}
int main() {
	int number;
	while (cin >> number) {
		if (number == -1)
			break;
		else {
			int solution = answer(number);
			cout << solution << endl;
			continue;
		}
	}
	return 0;
}