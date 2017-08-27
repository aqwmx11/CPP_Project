#include <iostream>;
using namespace std;
int main() {
	int n = 0;
	cin >> n;
	char enter[10];
	cin.getline(enter, 5);
	for (int i = 0; i < n; i++) {
		char str[500];
		cin.getline(str, 500);
		for (int j = 0; str[j] != '\0'; j++) {
			switch (str[j]) {
			case 'A':
				cout << 'T';
				break;
			case 'T':
				cout << 'A';
				break;
			case 'G':
				cout << 'C';
				break;
			case 'C':
				cout << 'G';
				break;
			}
		}
		cout << endl;
	}
	return 0;
}