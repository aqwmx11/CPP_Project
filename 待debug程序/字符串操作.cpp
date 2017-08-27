#include <iostream>;
#include<string>;
#include <stdlib.h>;
using namespace std;
string words[25];
int number;
string copy(int N, int X, int L);
string add(string S1, string S2);
string find(string S, int N);
string rfind(string S, int N);
string insert(string S, int N, int X);
string reset(string S, int N);
string print(int N);
string str[10];
string analyze() {
	cin >> str[0];
	if (str[0] == "copy") {
		int n = atoi(analyze().c_str());
		int x = atoi(analyze().c_str());
		int l = atoi(analyze().c_str());
		return copy(n, x, l);
	}
	else if (str[0] == "add")
		return add(analyze(), analyze());
	else if (str[0] == "find") {
		int n1 = atoi(analyze().c_str());
		return find(analyze(),n1);
	}
	else if (str[0] == "rfind") {
		int n2 = atoi(analyze().c_str());
		return rfind(analyze(), n2);
	}
	//else if (str[0] == "insert") {
		//int n3 = atoi(analyze().c_str());
		//int x3 = atoi(analyze().c_str());
		//return insert(analyze(), n3, x3);
	//}
	else if (str[0] == "reset") {
		int n4 = atoi(analyze().c_str());
		return reset(analyze(), n4);
	}
	else if (str[0] == "print") {
		int n5 = atoi(analyze().c_str());
		return print(n5);
	}
	else if (str[0] == "printall") {
		for (int i = 1; i <= number; i++)
			print(i);
	}
	else
		return str[0];
}
string copy(int N, int X, int L) {
	string s6 = words[N-1];
	return s6.substr(X, L);
}
string add(string S1, string S2) {
	int state = 1;
	for (int i = 0; i < S1.size(); i++) {
		if (S1.at(i) < '0' || S1.at(i) > '9') {
			state = 0;
			break;
		}
	}
	for (int i = 0; i < S2.size(); i++) {
		if (S2.at(i) < '0' || S2.at(i) > '9') {
			state = 0;
			break;
		}
	}
	if (state == 0)
		return S1 + S2;
	else {
		int a7 = atoi(S1.c_str());
		int b7 = atoi(S2.c_str());
		if (a7 >= 0 && a7 <= 99999 && b7 >= 0 && b7 <= 99999) {
			int c7 = a7 + b7;
			char temp[10];
			sprintf_s(temp, "%d", c7);
			return temp;
		}
		else
			return S1 + S2;
	}
}
string find(string S, int N) {
	int pos = words[N-1].find(S);
	int answer;
	if (pos == string::npos)
		answer= S.size();
	else
		answer=pos;
	char tmp[10];
	sprintf_s(tmp, "%d", answer);
	return tmp;
}
string rfind(string S, int N) {
	int pos2 = words[N - 1].rfind(S);
	int answer2;
	if (pos2 == string::npos)
		answer2 = S.size();
	else
		answer2 = pos2;
	char tmp2[10];
	sprintf_s(tmp2, "%d", answer2);
	return tmp2;
}
//string insert(string S, int N, int X) {
	//words[N - 1].insert(X, S);
	//return "success";
//}
string reset(string S, int N) {
	words[N - 1].swap(S);
	return"success";
}
string print(int N) {
	cout << words[N - 1] << endl;
	return "success";
}
int main() {
	int number = 0;
	cin >> number;
	for (int i = 0; i < number; i++)
		cin >> words[i];
	while (cin.peek() != 'o')
		analyze();
	return 0;
}

