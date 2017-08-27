#include <iostream>;
#include <set>;
#include <iterator>;
#include <string>;
using namespace std;
multiset<int> mset;
set<int> temp;
void myadd(const int & a) {
	mset.insert(a);
	temp.insert(a);
	cout << mset.count(a) << endl;
}
void mydel(const int & a) {
	cout << mset.count(a) << endl;
	mset.erase(a);
}
void myask(const int & a) {
	if (temp.find(a) == temp.end())
		cout << "0 0" << endl;
	else {
		cout << "1 ";
		cout << mset.count(a) << endl;
	}
}
int main() {
	int n = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string command;
		int num;
		cin >> command >> num;
		if (command == "add")
			myadd(num);
		else if (command == "del")
			mydel(num);
		else if (command == "ask")
			myask(num);
	}
	return 0;
}