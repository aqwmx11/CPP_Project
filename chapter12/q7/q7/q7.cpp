#include <iostream>;
using namespace std;
class Sample {
public:
	int v;
	Sample() {};
	Sample(int n) :v(n) {};
	Sample(Sample&x) { v = 2 + x.v; }
};
Sample PrintAndDouble(Sample o) {
	cout << o.v;
	o.v = 2 * o.v;
	return o;
}
int main() {
	Sample a(5);
	Sample b = a;
	Sample c = PrintAndDouble(b);//输出9，因为b作为形参在调用时也要执行复制构造函数
	cout << endl;
	cout << c.v << endl;//输出20，因为o作为输出结果也要执行复制构造函数
	Sample d;
	d = a;
	cout << d.v << endl;
	return 0;
}