#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;
class MyString {
public:
	string str;
	//三种构造函数
	MyString():str(""){}
	MyString(string s):str(s){}
	MyString(char* s) :str(s) {}
	//重载加法函数
	MyString operator +(const MyString& mystr) {
		return MyString(str + mystr.str);
	}
	MyString operator +(const string& s) {
		return MyString(str + s);
	}
	MyString operator+(const char* s) {
		return MyString(str +" "+ s);
	}
	//重载+=函数
	MyString& operator +=(const string& s) {
		str += s;
		return *this;
	}
	//重载[]函数
	char& operator[](int n) {
		return str[n];
	}
	//重载<函数
	bool operator<(const MyString& mystr) {
		if (str[0] < mystr.str[0])
			return true;
		else
			return false;
	}
	//重载==函数
	bool operator==(const MyString& mystr) {
		if (str[0] == mystr.str[0])
			return true;
		else
			return false;
	}
	//重载>函数
	bool operator>(const MyString& mystr) {
		if (str[0] > mystr.str[0])
			return true;
		else
			return false;
	}
	//重载()函数
	string operator()(int a, int b) {
		return str.substr(a, b);
	}
};
//重载输出流函数
ostream& operator<< (ostream& os, const MyString& mystr) {
	os << mystr.str.c_str();
	return os;
}
//重载+函数
MyString operator+(const char* s, const MyString& mystr) {
	return MyString(s + mystr.str);
}
//比较函数
int CompareString(const void* e1, const void* e2) {
	MyString *s1 = (MyString*)e1;
	MyString *s2 = (MyString*)e2;
	if (*s1 < *s2)
		return -1;
	else if (*s1 == *s2)
		return 0;
	else if (*s1 > *s2)
		return 1;
}
int main() {
	MyString s1("abcd-"), s2, s3("efgh-"), s4(s1);
	MyString SArray[4] = { "big","me","about","take"};
	cout << "1. " << s1 << s2 << s3 << s4 << endl;
	s4 = s3;
	s3 = s1 + s3;
	cout << "2. " << s1 << endl;
	cout << "3. " << s2 << endl;
	cout << "4. " << s3 << endl;
	cout << "5. " << s4 << endl;
	cout << "6. " << s1[2] << endl;
	s2 = s1;
	s1 = "ijkl-";
	s1[2] = 'A';
	cout << "7. " << s2 << endl;
	cout << "8. " << s1 << endl;
	s1 += "mnop";
	cout << "9. " << s1 << endl;
	s4 = "qrst-" + s2;
	cout << "10. " << s4 << endl;
	s1 = s2 + s4 + "uvw" + "xyz";
	cout << "11. " << s1 << endl;
	qsort(SArray, 4, sizeof(MyString), CompareString);
	for (int i = 0; i < 4; ++i)
		cout << SArray[i] << endl;
	cout << s1(0, 4) << endl;
	cout << s1(5, 10) << endl;
	return 0;
}