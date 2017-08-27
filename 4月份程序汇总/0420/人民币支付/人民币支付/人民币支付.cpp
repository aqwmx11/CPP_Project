#include <iostream>;
using namespace std;
int main() {
	int cash = 0;
	cin >> cash;
	int baiyuan, wushiyuan, ershiyuan, shiyuan, wuyuan, yiyuan = 0;
	baiyuan = cash / 100;
	wushiyuan = (cash - 100 * baiyuan) / 50;
	ershiyuan = (cash - 100 * baiyuan - 50 * wushiyuan) / 20;
	shiyuan = (cash - 100 * baiyuan - 50 * wushiyuan - 20 * ershiyuan) / 10;
	wuyuan = (cash - 100 * baiyuan - 50 * wushiyuan - 20 * ershiyuan - 10 * shiyuan) / 5;
	yiyuan = (cash - 100 * baiyuan - 50 * wushiyuan - 20 * ershiyuan - 10 * shiyuan - 5 * wuyuan) / 1;
	cout << baiyuan << endl;
	cout << wushiyuan << endl;
	cout << ershiyuan << endl;
	cout << shiyuan << endl;
	cout << wuyuan << endl;
	cout << yiyuan << endl;
	return 0;
}