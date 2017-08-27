#include <iostream>;
#include <stack>;
using namespace std;
int main() {
	stack<int> stk;
	int a = 0;
	int tmp = 0;
	cin >> a;
	stk.push(a);
	while (cin >> tmp) {
		while (!stk.empty()) {
			if (stk.top() != tmp) {
				stk.push(tmp);
				break;
			}
			else {
				stk.pop();
				tmp = 1 - tmp;
			}
		}
		if (stk.empty())
			stk.push(tmp);
	}
	stack<int> result;
	while (!stk.empty()) {
		result.push(stk.top());
		stk.pop();
	}
	while (!result.empty()) {
		cout << result.top();
		result.pop();
	}
	return 0;
}