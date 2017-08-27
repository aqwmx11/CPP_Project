#include <iostream>;
using namespace std;
char str[102];
int letter[102];
int signal[102];
bool rightest(int a) {
	int state = 1;
	for (int i = a + 1; letter[i] != 0; i++) {
		if (letter[i] == 1) {
			state = 0;
			return 0;
			break;
		}
	}
	if (state == 1)
		return 1;
}
void getpartner(int b) {
	if (letter[b] == 1) {
		if (rightest(b)){
			int state2 = 0;
			if (str[b + 1] == '\0') {
				signal[b] = 2;
				letter[b] = 3;
			}
			else {
				for (int i = b + 1; letter[i] != 0; i++) {
					if (letter[i] == 2) {
						state2 = 1;
						signal[b] = 1;
						signal[i] = 1;
						letter[b] = 3;
						letter[i] = 3;
						break;
					}
					if (state2 == 0) {
						signal[b] = 2;
						letter[b] = 3;
					}
				}
			}
		}
	}
}
int main() {
	int sum = 0;
	while (cin.getline(str, 101)) {
		for (int i = 0; str[i] != '\0'; i++) {
			if (str[i] == '(') {
				letter[i] = 1;
				sum++;
			}
			else if (str[i] == ')')
				letter[i] = 2;
			else letter[i] = 3;
		}
		for (int i = 0; i < sum; i++)
			for (int j = 0; str[j] != 0; j++) {
				getpartner(j);
			}
		for (int i = 0; str[i] != 0; i++) {
			if (str[i] == ')'&&signal[i] == 0) {
				signal[i] = 3;
			}
		}
		cout << str << endl;
		for (int i = 0; str[i] != 0; i++) {
			if (str[i] == '('&&signal[i] == 2)
				cout << '$';
			else if (str[i] == ')'&&signal[i] == 3)
				cout << '?';
			else cout << ' ';
		}
		cout << endl;
		for (int i = 0; i < 102; i++) {
			str[i] = '\0';
			letter[i] = 0;
			signal[i] = 0;
		}
	}
	return 0;
}