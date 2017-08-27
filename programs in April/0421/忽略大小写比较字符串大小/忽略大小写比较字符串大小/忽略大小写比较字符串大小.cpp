#include <iostream>;
using namespace std;
int main() {
	char a[80];
	char b[80];
	cin.getline(a, 80);
	cin.getline(b, 80);
	for (int i = 0; a[i] != '\0'; i++) {
		if (65 <= a[i] && a[i] <= 90) {
			a[i] = a[i] + 32;
		}
	}
	for (int i = 0; b[i] != '\0'; i++) {
		if (65 <= b[i] && b[i] <= 90) {
			b[i] = b[i] + 32;
		}
	}
	int j = 0;
	char result;
	while (a[j] != '\0' && (a[j] == b[j])){
		j++;
	}
	if (a[j] > b[j]) {
		result = '>';
	}
	else if (a[j] < b[j]) {
		result = '<';
	}
	else{
		result = '=';
	}
	cout << result << endl;
	return 0;
}