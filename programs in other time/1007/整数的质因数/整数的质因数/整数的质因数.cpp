#include <iostream>;
#include <vector>;
using namespace std;
vector<int> prime_factors(int n) {
	vector<int> factors;
	for (int i = 2; i <= n / i; i++) {
		while (n%i == 0) {
			factors.push_back(i);
			n /= i;
		}
	}
	if (n > 1)
		factors.push_back(n);
	return factors;
}
int main() {
	int num;
	cin >> num;
	for (int i = 0; i < prime_factors(num).size(); i++)
	{
		cout << prime_factors(num)[i] << endl;
	}
	return 0;
}