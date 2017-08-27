#include <iostream>
#include <string>
using namespace std;
template <class T>
class CMyistream_iterator {
private:
	istream & i;
	T a;
public:
	CMyistream_iterator(istream& input) :i(input)
	{
		i >> a;
	}
	T operator * () {
		return a;
	}
	void operator ++ () {
		i >> a;
	}
};
int main()
{
	CMyistream_iterator<int> inputInt(cin);
	int n1, n2, n3;
	n1 = *inputInt; //¶ÁÈë n1
	int tmp = *inputInt;
	cout << tmp << endl;
	inputInt++;
	n2 = *inputInt; //¶ÁÈë n2
	inputInt++;
	n3 = *inputInt; //¶ÁÈë n3
	cout << n1 << "," << n2 << "," << n3 << endl;
	CMyistream_iterator<string> inputStr(cin);
	string s1, s2;
	s1 = *inputStr;
	inputStr++;
	s2 = *inputStr;
	cout << s1 << "," << s2 << endl;
	return 0;
}