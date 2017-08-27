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
	Sample c = PrintAndDouble(b);//���9����Ϊb��Ϊ�β��ڵ���ʱҲҪִ�и��ƹ��캯��
	cout << endl;
	cout << c.v << endl;//���20����Ϊo��Ϊ������ҲҪִ�и��ƹ��캯��
	Sample d;
	d = a;
	cout << d.v << endl;
	return 0;
}