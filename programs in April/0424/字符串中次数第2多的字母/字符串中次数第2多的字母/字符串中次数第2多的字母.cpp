#include <iostream>;
using namespace std;
int main() {
	char str[600];
	cin.getline(str, 510);
	int a[30];
	int count[30];
	int state[30];
	int rank[30];
	int p = 0;
	for (int i = 0; i < 26; i++) {
		a[i] = 0;
		count[i] = 0;
		state[i] = 0;
		rank[i] = 0;
	}
	for (int i = 0; str[i] != '\0'; i++) {
		p = str[i];
		if (p >= 65 && p <= 90) {
			p = p - 65;
			a[p]++;
		}
		else if (p >= 97 && p <= 122) {
			p = p - 97;
			a[p]++;
		}
	}
	int max = 0;
	for (int i = 0; i < 26; i++) {
		if (a[i] > max)
			max = a[i];
	}
	for (int i = 0; i < 26; i++) {
		if (a[i] == max)
			a[i] = 0;
	}
	for (int i = 0; i < 26; i++) {
		for (int j = 0; j < 26; j++) {
			if (a[j] > a[i])
				count[i]++;
		}
	}
	for (int i = 0; i < 26; i++) {
		if (count[i] == 0)
			state[i] = 1;
	}
	for (int i = 0; i < 26; i++) {
		for (int j = 0; str[j] != '\0'; j++) {
			if (str[j] == i + 65 || str[j] == i + 97) {
				rank[i] = j;
				break;
			}
		}
	}
	int begin;
	for (int i = 0; i < 26; i++) {
		if (state[i] == 1) {
			begin = i;
			break;
		}
	}
	for (int i = begin; i < 26; i++) {
		if (state[i] == 1 && rank[i] < rank[begin])
			begin = i;
	}
	char capital = begin + 65;
	char small = begin + 97;
	cout << capital << '+' << small << ':' << a[begin] << endl;
	return 0;
}