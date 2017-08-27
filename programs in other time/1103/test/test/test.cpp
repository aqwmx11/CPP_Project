#include <iostream>;
using namespace std;
int main() {
	int i = 1;
	cout << "answer 1 is " << (i++) + (++i) << endl;
	cout << "the value of i is " << i << endl;
	return 0;
}