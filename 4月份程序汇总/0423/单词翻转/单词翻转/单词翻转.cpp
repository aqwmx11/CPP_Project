#include <iostream>;
using namespace std;
char str[501];
void invert(int a) {
	if (str[a + 1] == ' ')
		cout << str[a];
	else if (str[a + 1] == '\0')
		cout << str[a];
	else {
		invert(a + 1);
		cout << str[a];
	}
}
int main() {
	for (int i = 0; i <= 500; i++) {
		str[i] = '\0';
	}
	cin.getline(str, 500);
	int flag = 0;
	for (int i = 0; str[i] != '\0'; i++) {
		if (str[i] == ' '){
			cout << ' ';
			flag = 0;
		}
		else {
			if (flag == 0) {
				invert(i);
				flag = 1;
			}
			else
				flag = 1;
		}
	}
	return 0;
}