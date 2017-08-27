#include <iostream>;
using namespace std;
int main() {
	char str[20];
	char substr[10];
	while (cin >> str >> substr) {
		int insert = 0;
		int sum = 0;
		int num = 0;
		for (int i = 0; str[i] != '\0'; i++) {
			num++;
		}
		for (int i = 0; str[i] != '\0'; i++) {
			if (str[i] > str[insert]) {
				insert = i;
			}
		}
		char temp[20];
		for (int i =0; str[i] != '\0'; i++) {
			temp[i] = str[insert + i + 1];
		}
		for (int i = 0; substr[i] != '\0'; i++) {
			str[insert + i + 1] = substr[i];
			sum++;
		}
		for (int i = 0; temp[i] != '\0'; i++) {
			str[insert + sum + 1 + i] = temp[i];
		}
		str[num + sum] = '\0';
		cout << str << endl;
	}
	return 0;
}