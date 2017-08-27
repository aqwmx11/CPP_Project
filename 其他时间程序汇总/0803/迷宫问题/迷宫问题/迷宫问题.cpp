#include <iostream>;
#include <queue>;
using namespace std;
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
struct node {
	int x, y, state, pre;
	node(int a=0, int b=0, int c=0,int d=-1) {
		x = a; y = b; state = c; pre = d;
	}
};
queue<node> q;
node maze[25];
void print(node a) {
	if (a.pre == -1) {
		cout << "(0, 0)" << endl;
		return;
	}
	else {
		print(maze[a.pre]);
		cout << '(' << a.x << ", " << a.y << ')' << endl;
	}
}
int visited[5][5] = { 0 };
void bfs(node a) {
	q.push(a);
	visited[0][0] = 1;
	while (!q.empty()) {
		for (int i = 0; i < 4; i++) {
			int nx = q.front().x + dx[i];
			int ny = q.front().y + dy[i];
			if (nx < 0 || nx>4 || ny < 0 || ny>4)
				continue;
			if (visited[nx][ny] == 1)
				continue;
			if (maze[nx * 5 + ny].state == 1)
				continue;
			visited[nx][ny] = 1;
			maze[5 * nx + ny].pre = q.front().x * 5 + q.front().y ;
			q.push(maze[5*nx + ny]);
			if (nx == 4 && ny == 4)
				break;
		}
		q.pop();
	}
}
int main() {
	for (int i = 0; i < 25; i++) {
		maze[i].x = i / 5;
		maze[i].y = i - maze[i].x * 5;
		maze[i].pre = -1;
	}
	for (int i = 0; i < 25; i++) {
		cin >> maze[i].state;
	}
	bfs(maze[0]);
	print(maze[24]);
	return 0;
}