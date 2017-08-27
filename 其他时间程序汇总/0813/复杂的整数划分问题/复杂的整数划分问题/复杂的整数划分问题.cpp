#include <iostream>;
using namespace std;
int dp[52][52];
int dp1[52][52];
int f[52][52], g[52][52];
int N, K;
int main() {
	for (int i = 1; i <= 50; i++)
		dp[i][1] = 1;
	for (int i = 2; i <= 50; i++) {
		for (int j = 2; j <= i; j++) {
			if (i == j)
				dp[i][j] = 1;
			else
				dp[i][j] = dp[i - 1][j - 1] + dp[i - j][j];
		}
	}
	dp1[1][1] = 1;
	for (int i = 2; i <= 50; i++)
		dp1[i][1] = 0;
	for (int i = 1; i <= 50; i++) {
		for (int j = 2; j <= 50; j++) {
			if (i < j)
				dp1[i][j] = dp1[i][i];
			else if (i == j)
				dp1[i][j] = 1 + dp1[i][j - 1];
			else if (i>j)
				dp1[i][j] = dp1[i - j][j - 1] + dp1[i][j - 1];
		}
	}
	for (int i = 1; i <= 50; i++)
		f[i][1] = i % 2;
	for (int i = 1; i <= 50; i++) {
		for (int j = 2; j <= 50; j++) {
			if ((i - j) % 2 == 1 || i < j)
				f[i][j] = 0;
			else if (i == j)
				f[i][j] = 1;
			else {
				if (i-2*j>0)
					f[i][j] = f[i - 1][j - 1] + f[i - 2 * j][j];
				else 
					f[i][j] = f[i - 1][j - 1] ;
			}
		}
	}
	while (cin >> N >> K) {
		cout << dp[N][K] << endl;
		cout << dp1[N][N] << endl;
		int answer = 0;
		for (int i = 1; i <= N; i++)
			answer += f[N][i];
		cout << answer << endl;
	}
	return 0;
}