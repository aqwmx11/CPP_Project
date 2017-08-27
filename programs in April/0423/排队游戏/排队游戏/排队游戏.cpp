#include <iostream>;
using namespace std;
int suc[100];
int pre[100];
int a[100];
int number = 0;
int counts = 0;
int partner[100];
void queue() {
	for (int i = 0; i <= number - 1; i++) {
		if (a[i] == 1 && a[suc[i]] == 2) {
			partner[suc[i]] = i;
			a[suc[i]] = 0;
			suc[pre[i]] = suc[suc[i]];
			pre[suc[suc[i]]] = pre[i];
			counts++;
		}
	}
}
int main() {
	char str[100];
	cin.getline(str, 100);
	char boy = str[0];
	char girl;
	for (int i = 0; str[i] !='\0'; i++) {
		if (str[i] != boy) {
			girl = str[i];
			break;
		}
	}
	for (int i = 0; str[i] != '\0'; i++) {
		number++;
		if (str[i] == boy)
			a[i] = 1;
		else if (str[i] == girl)
			a[i] = 2;
		else
			a[i] = 0;
	}
	for (int i = 0; i < number - 1; i++) {
		suc[i] = i + 1;
	}
	for (int i = 1; i < number; i++) {
		pre[i] = i - 1;
	}
	int pairs = number / 2;
	while (counts < pairs) {
		queue();
	}
	for (int i = 0; str[i] != '\0'; i++) {
		if (str[i] == girl)
			cout << partner[i] << ' ' << i << endl;
	}
	return 0;
}