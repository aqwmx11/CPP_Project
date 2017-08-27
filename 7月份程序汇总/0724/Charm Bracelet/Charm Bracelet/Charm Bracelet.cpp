#include <algorithm>;
#include <iostream>;
using namespace std;
int main() {
	int d[3410];
	int w[3410];
	int solution[13000] = { 0 };
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		cin >> w[i] >> d[i];
	for (int i = 0; i < N; i++) {
		for (int j = M; j >= w[i]; j--)
			solution[j] = max(solution[j], solution[j - w[i]] + d[i]);
	}
	cout << solution[M] << endl;
	return 0;
}