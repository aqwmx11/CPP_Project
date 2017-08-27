#include <iostream>;
#include <queue>;
using namespace std;
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
char maze[201][201];
int R, C;
struct node {
	int x, y, visited, count;
	node(int a = 0, int b = 0, int c = 0, int d = 0) {
		x = a; y = b; visited = c; count = d;
	}
};
queue <node> q;
node mymaze[40500];
void bfs(node a) {
	q.push(a);
	a.visited = 1;
	a.count = 0;
	while (!q.empty()) {
		for (int i = 0; i < 4; i++) {
			int nx = q.front().x + dx[i];
			int ny = q.front().y + dy[i];
			if (nx < 0 || nx>R-1 || ny < 0 || ny>C-1)
				continue;
			if (mymaze[C*nx + ny].visited == 1)
				continue;
			if (maze[nx][ny] == '#')
				continue;
			mymaze[C*nx + ny].visited = 1;
			mymaze[C*nx + ny].count = q.front().count + 1;
			q.push(mymaze[C * nx + ny]);
			if (maze[nx][ny] == 'E')
				break;
		}
		q.pop();
	}
}
int main() {
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		int start, myend = 0;
		cin >> R >> C;
		for (int j = 0; j < R; j++) {
			for (int k = 0; k < C; k++) {
				cin >> maze[j][k];
				mymaze[C*j + k].x = j;
				mymaze[C*j + k].y = k;
				mymaze[C*j + k].visited = 0;
				mymaze[C*j + k].count = 0;
				if (maze[j][k] == 'S')
					start = C*j + k;
				if (maze[j][k] == 'E')
					myend = C*j + k;
			}
		}
		bfs(mymaze[start]);
		if (mymaze[myend].visited == 0)
			cout << "oop!" << endl;
		else
			cout << mymaze[myend].count << endl;
	}
	return 0;
}
