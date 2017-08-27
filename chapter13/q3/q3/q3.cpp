#include <iostream>
#include <cstring>
using namespace std;
class Complex {
private:
	double r, i;
public:
	void Print() {
		cout << r << "+" << i << "i" << endl;
	}
	Complex & operator = (const string & a) {
		int pos = a.find("+", 0);
		string real = a.substr(0, pos);
		r = atof(real.c_str());
		string img = a.substr(pos + 1, a.length() - pos - 2);
		i = atof(img.c_str());
		return *this;
	}
};
int main() {
	Complex a;
	a = "3+4i";
	a.Print();
	a = "5+6i";
	a.Print();
	return 0;
}
