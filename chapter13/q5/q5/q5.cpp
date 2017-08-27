#include <iostream>
using namespace std;
class Point {
private:
	int x;
	int y;
public:
	Point(int x_,int y_):x(x_),y(y_){}
	friend ostream& operator << (ostream & os, const Point& p);
};
ostream& operator <<(ostream & os, const Point& p) {
	os << "(" << p.x << "," << p.y << ")"<<"\n";
	return os;
}
int main() {
	cout << Point(4, 5) << Point(7, 8);
	return 0;
}