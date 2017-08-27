#include <iostream>;
#include <string>;
#include <queue>;
#include <cstring>;
#include <functional>;
using namespace std;
int main() {
	string inp;
	int floor = 1;
	int casenum = 1;
	int flag = 1;
	priority_queue <string, vector<string>, greater<string>> q[1500];
	while (cin >> inp) {
		if (inp[0] == '#')
			break;
		if (flag) {
			cout << "DATA SET " << casenum << ':' << endl;
			cout << "ROOT" << endl;
			flag = 0;
		}
		if (inp[0] == 'f')
			q[floor].push(inp);
		else if (inp[0] == 'd') {
			for (int i = 0; i < floor; i++)
				cout << "|     ";
			cout << inp << endl;
			floor++;
		}
		else if (inp[0] == '*' || inp[0] == ']') {
			while (!q[floor].empty()) {
				for (int i = 0; i < floor - 1; i++)
					cout << "|     ";
				cout << q[floor].top() << endl;
				q[floor].pop();
			}
			floor--;
		}
		if (inp[0] == '*') {
			flag = 1;
			floor = 1;
			casenum++;
			cout << endl;
		}
	}
	return 0;
}