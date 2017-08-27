#include <iostream>
using namespace std;
template <class T>
T Max(T a, T b) {
	cout << "TemplateMax" << endl;
	return 0;
}
double Max(double a, double b) {
	cout << "MyMax" << endl;
	return 0;
}
int main() {
	int i = 4, j = 5;
	Max(1.2, 3.4); //Êä³öMyMax
	Max(i, j);// Êä³öTemplateMax
	return 0;
}