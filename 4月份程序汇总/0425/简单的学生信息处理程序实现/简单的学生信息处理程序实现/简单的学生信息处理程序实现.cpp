#include <iostream>;
using namespace std;
class student {
private:
	char name[20];
	int age;
	char id[20];
	int grade1, grade2, grade3, grade4;
public:
	void init() {
		cin.getline(name, 15, ',');
		char comma;
		cin >> age >> comma;
		cin.getline(id, 15, ',');
		char comma1, comma2, comma3;
		cin >> grade1 >> comma1 >> grade2 >> comma2 >> grade3 >> comma3 >> grade4;
	}
	void getname() {
		cout << name;
	}
	void getage() {
		cout << age;
	}
	void getid() {
		cout << id;
	}
	void getgrade() {
		int average = (grade1 + grade2 + grade3 + grade4) / 4;
		cout << average;
	}
};
int main() {
	student A;
	A.init();
	A.getname();
	cout << ',';
	A.getage();
	cout << ',';
	A.getid();
	cout << ',';
	A.getgrade();
	cout << endl;
	return 0;
}