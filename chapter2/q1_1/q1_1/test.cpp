#include <iostream>;
#include <string>;
using namespace std;
void Print(char *p1, char*p2) {
	for (; p1 < p2; p1++) {
		cout << *p1;
	}
}
int main() {
	char *s = "Lexus";
	Print(s, s + 5);
	return 0;
}