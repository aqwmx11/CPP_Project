#include <iostream>;
using namespace std;
int main() {
	long long solution[260][260];
	for (int i = 0; i <= 250; i++) {
		solution[0][i] = 1;
		solution[i][i] = 1;
	}
	for (int i = 2; i <= 250; i++) {
		for (int j = i - 1; j > 0; j--) {
			if (i - 2 * j == 0 || i - 2 * j >= j)
				solution[i][j] = solution[i - 2 * j][j] + solution[i][j + 1];
			else
				solution[i][j] = solution[i][j + 1];
		}
	}
	int inp;
	while (cin >> inp) {
		if (inp == 0)
			break;
		else
			cout << inp << " " << solution[inp][1] << endl;
	}
	return 0;
}