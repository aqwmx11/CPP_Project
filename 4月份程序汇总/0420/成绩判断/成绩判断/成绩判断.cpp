#include <iostream>;
using namespace std;
int main() {
	int score = 0;
	cin >> score;
	if (score >= 95 && score <= 100) {
		cout << '1';
	}
	else if (score >= 90 && score < 95) {
		cout << '2';
	}
	else if (score >= 85 && score < 90) {
		cout << '3';
	}
	else if (score >= 80 && score < 85) {
		cout << '4';
	}
	else if (score >= 70 && score < 80) {
		cout << '5';
	}
	else if (score >= 60 && score < 70) {
		cout << '6';
	}
	else {
		cout << '7';
	}
	return 0;
}