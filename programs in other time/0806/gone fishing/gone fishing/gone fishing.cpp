#include <stdio.h>;
#include <queue>;
using namespace std;
struct node {
	int id, fish, down, time;
	friend bool operator < (const node &x, const node &y) {
		if (x.fish != y.fish)
			return x.fish < y.fish;
		else
			return x.id > y.id;
	}
};
node a[30];
priority_queue<node> q;
int h, n;
