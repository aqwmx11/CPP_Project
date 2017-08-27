#include <iostream>;
using namespace std;
int main() {
	int n, m = 0;
	int x, y = 0;
	cin >> n >> m;
	char str[150][150] = { '\0' };
	int state[150][150] = { 0 };
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> str[i][j];
			if (str[i][j] == 'S')
				state[i][j] = 0;
			else if (str[i][j] == 'T') {
				state[i][j] = -3;
				x = i;
				y = j;
			}
			else if (str[i][j] == '.')
				state[i][j] = -1;
			else if (str[i][j] == '#')
				state[i][j] = -2;
		}
	}
	int count = 0;
	while (state[x][y] == -3) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (state[i][j] == count) {
					if (i - 1 >= 0) {
						if (state[i - 1][j] < 0 && state[i - 1][j] != -2)
							state[i - 1][j] = count + 1;
					}
					if (j - 1 >= 0) {
						if (state[i][j-1] < 0 && state[i][j-1] != -2)
							state[i][j-1] = count + 1;
					}
					if (i + 1 < n) {
						if (state[i + 1][j] < 0 && state[i + 1][j] != -2)
							state[i + 1][j] = count + 1;
					}
					if (j + 1 < m) {
						if (state[i][j+1] < 0 && state[i][j+1] != -2)
							state[i][j+1] = count + 1;
					}
				}
			}
		}
		count++;
	}
	cout << count << endl;
	return 0;
}