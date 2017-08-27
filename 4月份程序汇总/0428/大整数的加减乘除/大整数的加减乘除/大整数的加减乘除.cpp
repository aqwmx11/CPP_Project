#include <iostream>;
#include <cstring>;
using namespace std;
class hugeint {
public:	
	int number[5000];
	friend ostream & operator<<(ostream & o, const hugeint & a);
	hugeint(const char * str) {
		int i, j;
		memset(number, 0, sizeof(number));
		for (i = strlen(str) - 1, j = 0; i >= 0; i--)
			number[j++] = str[i] - '0';
	}
	hugeint() {
		for (int i = 0; i < 5000; i++)
			number[i] = 0;
	}
	hugeint operator+(const hugeint & a) {
		hugeint tmp(*this);
		for (int i = 0; i < 4998; i++) {
			tmp.number[i] += a.number[i];
			if (tmp.number[i] >= 10) {
				tmp.number[i] -= 10;
				tmp.number[i + 1]++;
			}
		}
		return tmp;
	}
	hugeint & operator=(const hugeint & a) {
		for (int i = 0; i < 5000; i++)
			number[i] = a.number[i];
		return *this;
	}
	bool operator<(const hugeint & a) {
		int count1 = 0;
		int count2 = 0;
		for (int i = 4998; i>=0&&number[i] == 0; i--) {
			count1 = i;
		}
		for (int i = 4998;i>=0&& a.number[i] == 0; i--)
			count2 = i;
		if (count1>count2) {
			return 0;
		}
		else if (count1 < count2) {
			return 1;
		}
		else {
			int state = 0;
			for (int i = count1 - 1; i >= 0; i--) {
				if (number[i]<a.number[i]) {
					state = 1;
					return 1;
					break;
				}
				else if (number[i]>a.number[i]) {
					state = 1;
					return 0;
					break;
				}
			}
			if (state == 0)
				return 0;
		}
	}
	hugeint operator-(const hugeint&a) {
		hugeint temp(*this);
		if (temp < a) {
			for (int i = 0; i < 4000; i++) {
				temp.number[i] = a.number[i] - temp.number[i];
				if (temp.number[i] < 0) {
					temp.number[i] += 10;
					temp.number[i + 1]++;
				}
			}
			temp.number[4999] = 1;
		}
		else {
			for (int i = 0; i < 4000; i++) {
				temp.number[i] = temp.number[i]-a.number[i];
				if (temp.number[i] < 0) {
					temp.number[i] += 10;
					temp.number[i + 1]--;
				}
			}
		}
		return temp;
	}
	hugeint jinwei(hugeint a, int b) {
		hugeint c ;
		int count1 = 0;
		for (int i = 4998; i>=0&&a.number[i] == 0; i--)
			count1 = i;
		for (int i = 0; i < count1; i++)
			c.number[i + b] = a.number[i];
		return c;
	}
	hugeint operator*(const hugeint& a) {
		hugeint sum;
		hugeint temp(*this);
		int count1 = 0;
		for (int i = 4998; i>=0&&number[i] == 0; i--) 
			count1 = i;
		for (int i = 0; i < count1; i++) {
			for (int j = 0; j < number[i]; j++)
				sum = sum + jinwei(a,i);
		}
		return sum;
	}
	bool operator<=(const hugeint & a) {
		hugeint temp(*this);
		if (temp < a)
			return 1;
		else {
			hugeint b = temp - a;
			int state = 1;
			for (int i = 4998; i >= 0; i--) {
				if (b.number[i] != 0) {
					state = 0;
					return 0;
					break;
				}
			}
			if (state == 1)
				return 1;
		}
	}
	hugeint operator/(const hugeint& a) {
		hugeint temp(*this);
		int count1 = 0;
		int count2 = 0;
		for (int i = 4998; i>=0&&temp.number[i] == 0; i--) {
			count1 = i;
		}
		for (int i = 4998; i>=0&&a.number[i] == 0; i--)
			count2 = i;
		hugeint result;
		if (temp < a) {
			for (int i = 0; i < 5000; i++)
				result.number[i] = 0;
		}
		else {
			int flag = count1 - count2;
			for (int i = flag; i >= 0; i--) {
				int q = 0;
				for (int j = 0; j <= 9; j++) {
					if (jinwei(a, i) <= temp) {
						temp = temp - jinwei(a, i);
					}
					else {
						q = j;
						break;
					}
				}
				result.number[i] = q;
			}
		}
		return result;
	}
};
ostream & operator<<(ostream & o, const hugeint & a) {
	int zero = 0;
	int weishu = 0;
	for (int i = 4998; i >= 0; i--) {
		if (a.number[i] != 0) {
			weishu = i;
			break;
		}
	}
	for (int i = 0; i < 4999; i++) {
		if (a.number[i] != 0) {
			zero = 1;
			break;
		}
	}
	if (zero == 0) {
		o << zero;
		return o;
	}
	else if (a.number[4999] == 1) {
		o << '-';
		for (int i = weishu; i >= 0; i--)
			o << a.number[i];
		return o;
	}
	else {
		for (int i = weishu; i >= 0; i--)
			o << a.number[i];
		return o;
	}
}
int main() {
	char a[103];
	char b[103];
	char c;
	char d[5];
	cin.getline(a, 101);
	cin >> c;
	cin.getline(d, 2);
	cin.getline(b, 101);
	hugeint e(a);
	hugeint f(b);
	switch (c) {
	case '+':
		cout << e + f << endl;
		break;
	case '-':
		cout << e - f << endl;
		break;
	case '*':
		cout << e*f << endl;
		break;
	case '/':
		cout << e / f << endl;
		break;
	}
	return 0;
}