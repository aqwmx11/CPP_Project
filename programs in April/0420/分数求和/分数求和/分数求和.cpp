#include <iostream>;
using namespace std;
int main() {
	int n,gys;
	cin >> n;
	int sumn = 0, sumd = 1;
	while (n--) {
		int num, deno;
		char slash;
		cin >> num >> slash >> deno;
		sumn = sumn*deno + num*sumd;
		sumd = sumd*deno;
	}
	int min = 0;
	if (sumn > sumd) {
		min = sumd;
	}
	else {
		min = sumn;
	}
	for (int i = min; i > 0; i--) {
		if (sumn%i == 0 && sumd%i == 0) {
			gys = i;
			break;
		}
	}
	sumn = sumn / gys;
	sumd = sumd / gys;
	if (sumd > 1) {
		cout << sumn << '/' << sumd << endl;
	}
	else {
		cout << sumn << endl;
	}
	return 0;
}