#include <iostream>;
#include <string>;
#include <list>;
#include <vector>;
#include <iterator>:
using namespace std;
class mylist {
public:
	int id;
	list<int> lst;
	mylist(int a) {
		id = a;
	}
	void printall() {
		lst.sort();
		list<int>::iterator pp;
		pp = lst.begin();
		for (pp = lst.begin(); pp != lst.end(); pp++)
			cout << *pp << " ";
		cout << endl;
	}
};
vector<mylist> v;
void mynew(int a) {
	v.push_back(mylist(a));
}
void myadd(int a, int b) {
	vector<mylist>::iterator p;
	p = v.begin();
	for (p = v.begin(); p < v.end(); p++) {
		if (p->id == a)
			break;
	}
	p->lst.push_back(b);
}
void mymerge(int a, int b) {
	vector<mylist>::iterator p1;
	p1 = v.begin();
	vector<mylist>::iterator q1;
	q1 = v.begin();
	for (p1 = v.begin(); p1 < v.end(); p1++) {
		if (p1->id == a)
			break;
	}
	for (q1 = v.begin(); q1 < v.end(); q1++) {
		if (q1->id == b)
			break;
	}
	p1->lst.sort();
	q1->lst.sort();
	p1->lst.merge(q1->lst);
}
void myunique(int a) {
	vector<mylist>::iterator p2;
	p2 = v.begin();
	for (p2 = v.begin(); p2 < v.end(); p2++) {
		if (p2->id == a)
			break;
	}
	p2->lst.sort();
	p2->lst.unique();
}
void myout(int a) {
	vector<mylist>::iterator p3;
	p3 = v.begin();
	for (p3 = v.begin(); p3 < v.end(); p3++) {
		if (p3->id == a)
			break;
	}
	p3->printall();
}
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		if (s == "new") {
			int a1;
			cin >> a1;
			mynew(a1);
		}
		else if (s == "add") {
			int a2, b2;
			cin >> a2>>b2;
			myadd(a2, b2);
		}
		else if (s == "merge") {
			int a3, b3;
			cin >> a3>>b3;
			mymerge(a3, b3);
		}
		else if (s == "unique") {
			int a4;
			cin >> a4;
			myunique(a4);
		}
		else if (s == "out") {
			int a5;
			cin >> a5;
			myout(a5);
		}
		else {
			cout << "invalid operator!" << endl;
			break;
		}
	}
	return 0;
}

