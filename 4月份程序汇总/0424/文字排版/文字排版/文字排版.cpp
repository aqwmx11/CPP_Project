#include <iostream>;
using namespace std;
int main() {
	int n = 0;
	cin >> n;
	char enter[10];
	cin.getline(enter, 3);
	char str[5001];
	cin.getline(str, 5000);
	int begin[5001];
	int end[5001];
	int flag = 1;
	int length[5001];
	int character = 0;
	begin[0] = 0;
	for (int i = 1; i < n; i++) {
		for (int j = begin[i-1]+1; str[j] !='\0'; j++) {
			if (str[j] == ' ')
				flag = 0;
			else if (flag == 0) {
				begin[i] = j;
				flag = 1;
				break;
			}
			else
				flag = 1;
		}
	}
	int temp = 0;
	for (int i = 0; i < n; i++) {
		for (int j = temp; str[j] != 0; j++) {
			if (str[j] != ' ' && (str[j + 1] == ' ' || str[j + 1] == '\0')) {
				end[i] = j;
				temp = j+1;
				break;
			}
		}
	}
	for (int i = 0; i < n; i++)
		length[i] = end[i] - begin[i] + 1;
	for (int i = 0; i < n - 1; i++){
		if (character + length[i] + 1 + length[i + 1] <= 80) {
			for (int j = begin[i]; j <= end[i]; j++)
				cout << str[j];
			cout << ' ';
			character = character + length[i] + 1;
		}
		else {
			for (int j = begin[i]; j <= end[i]; j++)
				cout << str[j];
			cout << endl;
			character = 0;
		}
	}
	for (int i = begin[n - 1]; i <= end[n - 1]; i++)
		cout << str[i];
	cout << endl;
	return 0;
}