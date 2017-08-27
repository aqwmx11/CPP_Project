#include <iostream>
#include <string>
#include <map>
#include <iterator>
#include <algorithm>
using namespace std;
template <class T1,class T2,class compare=less<T1> >
class MyMultimap {
public:
	multimap<T1, T2, compare> mymmap;
	class iterator {
	public:
		multimap<T1, T2, compare>* mypoint;
		iterator() {
			mypoint = mymmap.begin();
		}
	};
	void insert(pair<T1,T2> mypair) {
		mymmap.insert(mypair);
	}
	typename multimap<T1, T2, compare>::iterator begin() {
		return mymmap.begin();
	}
	typename multimap<T1, T2, compare>::iterator end() {
		return mymmap.end();
	}
	void Set(const T1 & a, const T2 & b) {
		typename multimap<T1, T2, compare>::iterator p;
		p = mymmap.begin();
		for (p = mymmap.begin(); p != mymmap.end(); p++) {
			if (p->first == a)
				p->second = b;
		}
	}
	void clear() {
		mymmap.clear();
	}
	typename multimap<T1, T2, compare>::iterator find(const T1 & a) {
		return mymmap.find(a);
	}
	friend ostream& operator << (ostream & o, multimap<T1, T2, compare> & a)
	{
		o << "(" << a->first << "," << a->second << ")";
		return o;
	}

};
struct Student
{
	string name;
	int score;
};
template <class T>
void Print(T first, T last) {
	for (; first != last; ++first)
		cout << *first << ",";
	cout << endl;
}
int main()
{

	Student s[] = { { "Tom", 80 }, { "Jack", 70 },
	{ "Jone", 90 }, { "Tom", 70 }, { "Alice", 100 } };
	MyMultimap<string, int> mp;
	for (int i = 0; i<5; ++i)
		mp.insert(make_pair(s[i].name, s[i].score));
	Print(mp.begin(), mp.end()); //按姓名从大到小输出

	mp.Set("Tom", 78); //把所有名为"Tom"的学生的成绩都设置为78
	Print(mp.begin(), mp.end());


	MyMultimap<int, string, less<int> > mp2;
	for (int i = 0; i<5; ++i)
		mp2.insert(make_pair(s[i].score, s[i].name));

	Print(mp2.begin(), mp2.end()); //按成绩从小到大输出
	mp2.Set(70, "Error");          //把所有成绩为70的学生，名字都改为"Error"
	Print(mp2.begin(), mp2.end());
	cout << "******" << endl;

	mp.clear();
	/*
	string name;
	string cmd;
	int score;
	while (cin >> cmd) {
		if (cmd == "A") {
			cin >> name >> score;
			if (mp.find(name) != mp.end()) {
				cout << "error" << endl;
			}
			mp.insert(make_pair(name, score));
		}
		else if (cmd == "Q") {
			cin >> name;
			MyMultimap<string, int>::iterator p = mp.find(name);
			if (p != mp.end()) {
				cout << p->second << endl;
			}
			else {
				cout << "Not Found" << endl;
			}
		}
	}
	*/
	return 0;
}