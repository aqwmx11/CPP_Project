#include <cstdio>
#include <string.h>
#include <queue>
using namespace std;
const int flip[16] = { 0xC800, 0xE400, 0x7200, 0x3100, 0x8C80, 0x4E40, 0x2720, 0x1310, 0x8C8, 0x4E4, 0x272, 0x131, 0x8C, 0x4E, 0x27, 0x13 };
const int done = 65535;
void BFS(int x)
{
	int cnt[done + 1];
	bool vis[done + 1];
	cnt[x] = 0;
	vis[x] = true;
	queue<int> q;
	q.push(x);
	int top, temp;
	while (!q.empty())
	{
		top = q.front();
		for (int i = 0; i<16; ++i)
		{
			temp = top ^ flip[i];
			if (!vis[temp])
			{
				cnt[temp] = cnt[top] + 1;
				if (!temp || temp == done)
				{
					printf("%d\n", cnt[temp]);
					return;
				}
				vis[temp] = true;
				q.push(temp);
			}
		}
		q.pop();
	}
	printf("Impossible\n");
}
int main(void)
{
	int x = 0;
	for (int i = 0; i<4; ++i)
	{
		for (int j = 0; j<4; ++j)
			x = (x << 1) + (getchar() == 'b' ? 1 : 0);
		getchar();
	}
	if (!x || x == done)
		printf("0\n");
	else
		BFS(x);
}