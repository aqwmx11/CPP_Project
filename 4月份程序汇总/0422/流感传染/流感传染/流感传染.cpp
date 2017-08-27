#include <iostream>;
using namespace std;
int location(int a, int b,int c){
	if (a == 0 && b == 0)
		return 1;
	else if (a == 0 && b != 0 && b != c - 1)
		return 2;
	else if (a == 0 && b == c - 1)
		return 3;
	else if (b == c-1 && a != 0 && a != c - 1)
		return 4;
	else if (a == c-1 && b == c - 1)
		return 5;
	else if (a == c - 1 && b != 0 && b != c - 1)
		return 6;
	else if (a == c - 1 && b == 0)
		return 7;
	else if (b == 0 && a != 0 && a != c - 1)
		return 8;
	else
		return 9;
}
int main() {
	int m, n = 0;
	int sum = 0;
	cin >> n;
	char room[100][100];
	int state[100][100];
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			state[i][j]=0;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> room[i][j];
			if (room[i][j] == '@')
				state[i][j] = 1;
			if (room[i][j] == '#')
				state[i][j] = 2;
		}
	}
	cin >> m;
	for (int p = 1; p <= m - 1; p++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				int loc = location(i, j, n);
				if (loc == 1 && room[i][j] == '@') {
					if (state[i + 1][j] == 0)
						state[i + 1][j] = 1;
					if (state[i][j+1] == 0)
						state[i][j+1] = 1;
				}
				if (loc == 2 && room[i][j] == '@') {
					if (state[i][j-1] == 0)
						state[i][j-1] = 1;
					if (state[i][j + 1] == 0)
						state[i][j + 1] = 1;
					if (state[i + 1][j] == 0)
						state[i + 1][j] = 1;
				}
				if (loc == 3 && room[i][j] == '@') {
					if (state[i][j-1] == 0)
						state[i][j-1] = 1;
					if (state[i+1][j] == 0)
						state[i+1][j] = 1;
				}
				if (loc == 4 && room[i][j] == '@') {
					if (state[i - 1][j] == 0)
						state[i - 1][j] = 1;
					if (state[i][j - 1] == 0)
						state[i][j - 1] = 1;
					if (state[i + 1][j] == 0)
						state[i + 1][j] = 1;
				}
				if (loc == 5 && room[i][j] == '@') {
					if (state[i - 1][j] == 0)
						state[i - 1][j] = 1;
					if (state[i][j - 1] == 0)
						state[i][j - 1] = 1;
				}
				if (loc == 6 && room[i][j] == '@') {
					if (state[i - 1][j] == 0)
						state[i - 1][j] = 1;
					if (state[i][j + 1] == 0)
						state[i][j + 1] = 1;
					if (state[i][j - 1] == 0)
						state[i][j - 1] = 1;
				}
				if (loc == 7 && room[i][j] == '@') {
					if (state[i - 1][j] == 0)
						state[i - 1][j] = 1;
					if (state[i][j + 1] == 0)
						state[i][j + 1] = 1;
				}
				if (loc == 8 && room[i][j] == '@') {
					if (state[i + 1][j] == 0)
						state[i + 1][j] = 1;
					if (state[i][j + 1] == 0)
						state[i][j + 1] = 1;
					if (state[i - 1][j] == 0)
						state[i - 1][j] = 1;
				}
				if (loc == 9 && room[i][j] == '@') {
					if (state[i + 1][j] == 0)
						state[i + 1][j] = 1;
					if (state[i][j + 1] == 0)
						state[i][j + 1] = 1;
					if (state[i - 1][j] == 0)
						state[i - 1][j] = 1;
					if (state[i][j - 1] == 0)
						state[i][j - 1] = 1;
				}
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (state[i][j] == 0)
					room[i][j] = '.';
				if (state[i][j] == 1)
					room[i][j] = '@';
				if (state[i][j] == 2)
					room[i][j] = '#';
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (room[i][j] == '@')
				sum++;
		}
	}
	cout << sum << endl;
	return 0;
}