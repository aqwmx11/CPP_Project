#include <iostream>;
#include <cstring>;
using namespace std;
int path[30][2];
char result[30];
int visited[30][30];
int p, q, sum, flag;
int dx[8] = { -1, 1, -2, 2, -2, 2, -1, 1 };
int dy[8] = { -2, -2, -1, -1, 1, 1, 2, 2 };
bool judge(int x, int y)
{
	if (x >= 1 && x <= p && y >= 1 && y <= q && visited[x][y]==0 && flag==0)
		return true;
	return false;
	}
void dfs(int r, int c, int step) {
	path[step][0] = r;
	path[step][1] = c;
	if (step == p*q) {
		flag = 1;
		return;
	}
	for (int m = 0; m < 8; m++) {
		int nx = r + dx[m];
		int ny = c + dy[m];
		if (judge(nx, ny)) {
			visited[nx][ny] = 1;
			dfs(nx, ny, step + 1);
			visited[nx][ny] = 0;
		}
	}
}
int main() {
	int casenum;
	cin >> casenum;
	for (int i = 0; i < casenum; i++) {
		cin >> p >> q;
		cout << "Scenario #" << i + 1 << ":" << endl;
		flag = 0;
		memset(path, 0, sizeof(path));
		memset(visited, 0, sizeof(visited));
		visited[1][1] = 1;
		dfs(1, 1, 1);
		if (flag == 1) {
			for (int j = 1; j <= p*q; j++) {
				result[j]=path[j][1] - 1 + 'A';
				cout << result[j]<<path[j][0];
			}
			cout << endl;
		}
		else
			cout << "impossible" << endl;
		cout << endl;
	}
	return 0;
}

