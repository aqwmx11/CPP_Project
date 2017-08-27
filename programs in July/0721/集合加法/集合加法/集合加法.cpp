#include <iostream>;
#include <queue>;
#include <functional>;
using namespace std;
int main() {
	int casenum;
	int anum, bnum;
	int tempa, tempb;
	int sum;
	int temp = 0;
	int answer = 0;
	int temp2=-1;
	int flag = 0;
	priority_queue<int, vector<int>, greater<int>> a;
	priority_queue<int> b;
	cin >> casenum;
	for (int i = 0; i < casenum; i++) {
		cin >> sum;
		cin >> anum;
		for (int j = 0; j < anum; j++) {
			cin >> tempa;
			a.push(tempa);
		}
		cin >> bnum;
		for (int j = 0; j < bnum; j++) {
			cin >> tempb;
			b.push(tempb);
		}
		while (!a.empty()) {
			if (b.empty() && flag == 1) {
				answer += temp;
				temp2 = a.top();
				a.pop();
				flag = 0;
			}
			if (a.top() == temp2) {
				answer += temp;
				a.pop();
			}
			else {
				if (b.empty()) 
					break;
				else {
					temp = 0;
					while (!b.empty()) {
						if (a.top() + b.top()>sum) {
							b.pop();
							flag = 0;
						}
						else if (a.top() + b.top() == sum) {
							b.pop();
							temp++;
							flag = 1;
						}
						else if (a.top() + b.top() < sum) {
							answer += temp;
							temp2 = a.top();
							a.pop();
							flag = 0;
							break;
						}
					}
				}
			}
		}
		cout << answer << endl;
		while (!a.empty())
			a.pop();
		while (!b.empty())
			b.pop();
		temp = 0;
		temp2 = -1;
		answer = 0;
		flag = 0;
	}
	return 0;
}