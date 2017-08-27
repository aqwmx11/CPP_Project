#include <iostream>;
#include <iomanip>;
using namespace std;
int getdays(int a, int b) {
	int runnian = 0;
	int c = 0;
	if ((a % 4 == 0 && a % 100 != 0) || (a % 100 == 0 && a % 400 == 0)) {
		runnian = 1;
	}
	if (b == 1 || b == 3 || b == 5 || b == 7 || b == 8 || b == 10 || b == 12) {
		return 31;
	}
	if (b == 4 || b == 6 || b == 9 || b == 11) {
		return 30;
	}
	if (b == 2) {
		if (runnian == 0) {
			return 28;
		}
		else if (runnian == 1) {
			return 29;
		}
	}
}
int main() {
	int year, month, day;
	int temp = 0;
	char ch1, ch2;
	cin >> year >> ch1 >> month >> ch2 >> day;
	temp = getdays(year, month);
	if (day != temp) {
		day++;
	}
	else {
		day = 1;
		if (month == 12) {
			month = 1;
			year++;
		}
		else {
			month++;
		}
	}
	cout << year << '-' << setfill('0') << setw(2) << month << '-' << setfill('0') << setw(2) << day;
	return 0;
}