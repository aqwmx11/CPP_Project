#include <iostream>;
using namespace std;
class Sample {
public:
	int v;
	Sample(int n) :v(n) {};
	Sample(const Sample& a) {
		v = a.v + 5;
	};
};
int main() {
	Sample a(5);
	Sample b = a;
	cout << b.v<<endl;
	return 0;
}