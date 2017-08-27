#include <iostream>;
using namespace std;
class complex {
public:
	double real;
	double imag;
	complex(double a = 0.0, double b = 0.0) :real(a), imag(b) {}
	
};
complex operator+ (complex m, complex j) {
	return complex(m.real + j.real, m.imag + j.imag);
}
int main() {
	complex c1(1.0, 2.0);
	complex c2(2.0, 5.0);
	complex csum = c1 + c2;
	cout << csum.real << '+' << csum.imag << 'i' << endl;
	return 0;
}