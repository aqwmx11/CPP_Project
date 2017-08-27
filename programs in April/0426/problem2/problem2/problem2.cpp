#include <iostream>
using namespace std;
class Sample{
public:
	int v;
	Sample(int n) :v(n) { }
	Sample(const Sample & p) { v = 2*p.v; }
};
int main() {
	Sample a(5);
	Sample b = a;
	cout << b.v;
	return 0;
}