#include <iostream>;
using namespace std;
int n, k;
char state[9][9];
int sum, temp;
int row[9];
void dfs(int i) {
	if (temp == k) {
		sum++;
		return;
	}
	if (i >= n)
		return;
	for (int j = 0; j < n; j++) {
		if (row[j] == 0 && state[i][j] == '#') {
			row[j] = 1;
			temp++;
			dfs(i + 1);
			row[j] = 0;
			temp--;
		}
	}
	dfs(i + 1);
}
int main() {
	while (true) {
		cin >> n >> k;
		if (n == -1 && k == -1)
			break;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++)
				cin >> state[i][j];
		}
		for (int i = 0; i < 9; i++)
			row[i] = 0;
		temp = 0;
		sum = 0;
		dfs(0);
		cout << sum << endl;
	}
	return 0;
}