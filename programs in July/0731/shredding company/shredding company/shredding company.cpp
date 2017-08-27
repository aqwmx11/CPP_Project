#include <iostream>;
#include <cstring>;
#include <string>;
#include <cmath>;
using namespace std;
int getlen(int n) {
	int temp = n;
	int length = 0;
	while (temp > 0) {
		temp = temp / 10;
		length++;
	}
	return length;
}
int getvalue(string s, int i) {
	int sum = 0;
	for (int j = 0; j < i;  j++) {
		sum += (s[j] - '0') * pow(10 ,i - j - 1);
	}
	return sum;
}
int getahead(int a, int b) {
	int len = getlen(a);
	int goal = a / pow(10, len - b);
	return goal;
}
int gettail(int a, int b) {
	return a%(int)pow(10, b);
}
int target, result, path, sum, p, flag = 0;
void dfs(string s, int len) {
	if (len == 0) {
		if (sum == result)
			flag = 1;
		else if (sum > result&&sum <= target) {
			flag = 0;
			result = sum;
			path = p;
		}
		return;
	}
	for (int i = 1; i <= len; i++) {
		int a = getvalue(s, i);
		sum += a;
		if (sum > target) {
			sum -= a;
			continue;
		}
		p = p * 10 + i;
		string s2="      ";
		for (int k = 0; k < len - i; k++)
			s2[k] = s[k + i];
		dfs(s2, len - i);
		sum -= a;
		p /= 10;
	}
	return;
}
int getmin(int a) {
	int temp = a;
	int summin = 0;
	while (temp > 0) {
		summin += temp % 10;
		temp /= 10;
	}
	return summin;
}
int main() {
	string numbers="      ";
	while (cin >> target >> numbers) {
		if (target == 0)
			break;
		int len = numbers.size();
		int n = getvalue(numbers, len);
		if (target == n) {
			cout << target << ' ' << n << endl;
			continue;
		}
		if (getmin(n) > target) {
			cout << "error" << endl;
			continue;
		}
		result = -1;
		sum = 0;
		path = 0;
		p = 0;
		flag = 0;
		dfs(numbers, len);
		if (flag == 1)
			cout << "rejected" << endl;
		else {
			cout << result << " ";
			int pathlength = getlen(path);
			for (int i = 1; i <= pathlength; i++) {
				int f = getahead(path, 1);
				cout << getahead(n, f) << " ";
				len -= f;
				n = gettail(n, len);
				path = gettail(path, pathlength - i);
			}
			cout << endl;
		}
	}
	return 0;
}