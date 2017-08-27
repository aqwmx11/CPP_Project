#include <iostream>;
using namespace std;
int main() {
	int step = 250;
	int flag = 1;//用于指示该次枚举的结果是否让所有的砖变成黄色
	int flag2 = 0;//用于指示是否完成枚举
	int casenum, n;
	cin >> casenum;
	for (int i = 0; i < casenum; i++) {
		cin >> n;
		char color[20][20] = { "" };
		int state[20][20] = { 0 };
		int operation[20][20] = { 0 };
		for (int j = 1; j < n+1; j++) {
			for (int k = 1; k < n + 1; k++) {
				cin >> color[j][k];
				if (color[j][k] == 'w')
					state[j][k] = 0;
				else
					state[j][k] = 1;
			}
		}
		while (flag2 == 0) {
			flag2 = 1;
			for (int p = 1; p <= n; p++) {
				if (operation[1][p] == 0)
					flag2 = 0;
			}
			for (int m = 2; m <= n; m++) {
				for (int p = 1; p <= n; p++) 
					operation[m][p] = (1 + state[m - 1][p] + operation[m - 1][p] + operation[m - 1][p - 1] + operation[m - 1][p + 1] + operation[m - 2][p]) % 2;
			}
			flag = 1;
			for (int p = 1; p <= n; p++) {
				if ((state[n][p]+operation[n][p]+operation[n][p-1]+operation[n][p+1]+operation[n-1][p])%2!=1)
					flag = 0;
			}
			if (flag == 1) {
				int currentstep = 0;
				for (int m = 1; m <= n; m++) {
					for (int p = 1; p <= n; p++) {
						if (operation[m][p] == 1)
							currentstep++;
					}
				}
				if (currentstep < step)
					step = currentstep;
			}
			for (int m = 2; m <= n; m++) {
				for (int p = 1; p <= n; p++)
					operation[m][p] = 0;
			}
			operation[1][1]++;
			int c = 1;
			while (operation[1][c]>1) {
				operation[1][c] = 0;
				c++;
				operation[1][c]++;
			}
		}
		if (step == 250)
			cout << "inf" << endl;
		else
			cout << step << endl;
		step = 250;
		flag = 1;
		flag2 = 0;
	}
	return 0;
}
