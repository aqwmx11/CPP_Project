#include <iostream>
#include <cstring>
#include <string>
using namespace std;
class MyString :public string {
public:
	MyString(const char* s):string(s){}
	string operator()(int a, int b) {
		return this->substr(a, b);
	}
};
int main() {
	MyString s1("hello,world");
	cout << s1(0, 4);
	return 0;
}