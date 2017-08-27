#include<iostream>;
#include<cstdio>;
#include<algorithm>;
using namespace std;
int n, s;
int c[10002], y[10002];
int main() {
	scanf("%d%d", &n, &s);
	for (int i = 0; i < n; i++)
		scanf("%d%d", &c[i], &y[i]);
	long long ans = 0;
	for (int i = 1; i < n; i++)
		c[i] = min(c[i - 1] + s, c[i]);
	for (int i = 0; i < n; i++)
		ans += c[i] * y[i];
	printf("%lld\n", ans);
	return 0;
}