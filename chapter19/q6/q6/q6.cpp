#include <iostream>
#include <map>
using namespace std;
class Gt {
public:
	bool operator()(const int& n1, const int& n2) const {
		return (n1 % 10) > (n2 % 10);
	}
};
int main() {
	typedef map<int, double, Gt> mmid;
	mmid MyMap;
	cout << MyMap.count(15) << endl;//���0
	MyMap.insert(mmid::value_type(15, 2.7));
	MyMap.insert(mmid::value_type(15, 99.3));//map������key��ͬ���ò��벻�ɹ�
	cout << MyMap.count(15) << endl;//���1
	MyMap.insert(mmid::value_type(30, 111.11));
	MyMap.insert(mmid::value_type(11,22.22));
	cout << MyMap[16] << endl;//���0����ͬʱ�Ѿ�������(16,0)�������
	for (mmid::const_iterator i = MyMap.begin(); i != MyMap.end(); ++i)
		cout << "(" << i->first << "," << i->second << ")" << ",";//˳�����(16,0),(15,2.7),(11,22.22),(30,111.11)
	return 0;
}