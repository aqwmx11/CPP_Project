#include<iostream>
using namespace std;
int a[105][105] = { 0 }, ans[105][105] = { 0 }, r = 0, c = 0, max1 = 0;
void dfs(int x, int y)
{
	int dx[5] = { 0, 0, 1, -1 }, dy[5] = { 1, -1, 0, 0 }, i = 0;
	if (ans[x][y]) return;
	for (ans[x][y] = 1, i = 0; i < 4; i++)
		if (x + dx[i] >= 0 && x + dx[i] < r && y + dy[i] >= 0 && y + dy[i] < c && a[x][y] > a[x + dx[i]][y + dy[i]])
		{
			dfs(x + dx[i], y + dy[i]);
			if (ans[x + dx[i]][y + dy[i]] + 1 > ans[x][y])
				ans[x][y] = ans[x + dx[i]][y + dy[i]] + 1;
		}
	if (max1 < ans[x][y]) max1 = ans[x][y];
}

int main()
{
	int i = 0, j = 0;
	cin >> r >> c;
	for (i = 0; i < r; i++)
		for (j = 0; j < c; j++)
			cin >> a[i][j];
	for (max1 = 0, i = 0; i < r; i++)
		for (j = 0; j < c; j++)
			dfs(i, j);
	cout << max1 << endl;
	return 0;
}