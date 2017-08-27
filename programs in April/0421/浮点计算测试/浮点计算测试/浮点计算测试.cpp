#include <iostream>;
using namespace std;
int main() {
	double price = 200;
	int K = 0;
	cin >> K;
	double rate =(double) K / 100;
	price = (double)price*(1 + rate);
	cout << price << endl;
}