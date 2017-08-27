#include <iostream>;
using namespace std;
int N;
int temp;
bool judge(int a) {
	temp = a;
	for (int i = 1; i <= N - 1; i++) {
		if ((N*temp + 1) % (N - 1) == 0) {
			temp = (N*temp + 1) / (N - 1);
		}
		else {
			return false;
			break;
		}
	}
	return true;
}
int main() {
	while (cin >> N&&N != 0) {
		int least = 1;
		while (!judge(least))
			least++;
		cout << N*temp + 1 << endl;
	}
	return 0;
}