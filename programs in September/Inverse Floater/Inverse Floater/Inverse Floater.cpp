//Author: illusion
//Date: 2017/9/30
//Description: code file for assignment 5-5

#include <iostream>
#include <iomanip>
using namespace std;

double hooLee(int t, int num) {
	return 0.06 - 0.005*t + 0.01*num;
}

double Q(int t, int num) {
	double myR = hooLee(t, num);
	if (myR > 0.085)
		return 0.035;
	else if (0.035 <= myR&&myR <= 0.085)
		return 0.12 - myR;
	else
		return 0.085;
}

double valAfterCoupon(int t, int heads) {
	if (t == 9)
		return (1000 + 1000 * Q(t, heads)) / (1 + hooLee(t, heads));
	else
		return (1000 * Q(t, heads) + 0.5*valAfterCoupon(t + 1, heads + 1) + 0.5*valAfterCoupon(t + 1, heads)) / (1 + hooLee(t, heads));
}

int main() {
	cout << fixed << setprecision(6) << valAfterCoupon(0, 0) << endl;
	return 0;
}