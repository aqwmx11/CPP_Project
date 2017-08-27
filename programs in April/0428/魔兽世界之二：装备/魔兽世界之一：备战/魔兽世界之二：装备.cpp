#include <iostream>;
#include <iomanip>;
#include <cstring>;
#include <string>;
using namespace std;
int hp[5];
int hour;
class headquarter {
public:
	int energy;
	int order[5];
	string name;
	int num[5];
	int flag;
	int state;
	headquarter(const int & a, const int &b, const int &c, const int &d, const int &e, const int & f, string g, const int & h) {
		energy = a;
		order[0] = b;
		order[1] = c;
		order[2] = d;
		order[3] = e;
		order[4] = f;
		name = g;
		for (int i = 0; i < 5; i++)
			num[i] = 0;
		flag = h;
		state = 1;
	}
	int getworriornum() {
		int sum = 0;
		for (int i = 0; i < 5; i++)
			sum += num[i];
		return sum;
	}
	void produce() ;
};
class warrior {
public:
	int id;
	int attack;
};
class dragon :public warrior {
public:
	int weapon;
	double morale;
	dragon(const int & a, const headquarter & b) {
		id = a+1;
		attack = hp[0];
		weapon = (a+1) % 3;
		morale = (double)b.energy / hp[0];
	}
};
class ninja :public warrior {
public:
	int weapon1;
	int weapon2;
	ninja(const int &a) {
		id = a+1;
		attack = hp[1];
		weapon1 = (a+1) % 3;
		weapon2 = (a + 2) % 3;
	}
};
class iceman :public warrior {
public:
	int weapon;
	iceman(const int &a) {
		id = a+1;
		attack = hp[2];
		weapon = (a+1) % 3;
	}
};
class lion :public warrior {
public:
	int loyalty;
	lion(const int &a, const headquarter & b) {
		id = a+1;
		attack = hp[3];
		loyalty = b.energy;
	}
};
class wolf :public warrior {
public:
	wolf(const int & a) {
		id = a+1;
		attack = hp[4];
	}
};
string getweaponname(const int & a) {
	string b;
	switch (a) {
	case 0:
		b = "sword";
		break;
	case 1:
		b = "bomb";
		break;
	case 2:
		b = "arrow";
		break;
	}
	return b;
}
	void headquarter::produce() {
		int count = 0;
		while (count < 5) {
			if (energy >= hp[flag]) {
				energy -= hp[flag];
				num[flag]++;
				int currentsum = getworriornum();
				switch (flag) {
				case 0: {
					dragon d(hour, *this);
					string d1 = getweaponname(d.weapon);
					cout << setfill('0') << setw(3) << hour << ' ' << name << " dragon " << currentsum << " born with strength " << hp[0] << ',' << num[0] << ' ' << "dragon" << " in "<<name<<" headquarter" << endl;
					cout << "It has a " << d1 << ",and it's morale is " << fixed << setprecision(2) << d.morale<<endl;
					flag = order[flag];
					break;
				}
				case 1:{
					ninja n(hour);
					string n1 = getweaponname(n.weapon1);
					string n2 = getweaponname(n.weapon2);
					cout << setfill('0') << setw(3) << hour << ' ' << name << " ninja " << currentsum << " born with strength " << hp[1] << ',' << num[1] << ' ' << "ninja" << " in "<<name<<" headquarter" << endl;
					cout << "It has a " << n1 << " and a " << n2 << endl;
					flag = order[flag];
					break;
				}
				case 2:{
					iceman i(hour);
					string i1 = getweaponname(i.weapon);
					cout << setfill('0') << setw(3) << hour << ' ' << name << " iceman " << currentsum << " born with strength " << hp[2] << ',' << num[2] << ' ' << "iceman" << " in " << name << " headquarter" << endl;
					cout << "It has a " << i1 << endl;
					flag = order[flag];
					break;
				}
				case 3: {
					lion l(hour, *this);
					cout << setfill('0') << setw(3) << hour << ' ' << name << " lion " << currentsum << " born with strength " << hp[3] << ',' << num[3] << ' ' << "lion" << " in " << name << " headquarter" << endl;
					cout << "It's loyalty is " << l.loyalty << endl;
					flag = order[flag];
					break;
				}
				case 4: {
					wolf w(hour);
					cout << setfill('0') << setw(3) << hour << ' ' << name << " wolf " << currentsum << " born with strength " << hp[4] << ',' << num[4] << ' ' << "wolf" << " in " << name << " headquarter" << endl;
					flag = order[flag];
					break;
				}
				}
				break;
			}
			else {
				count++;
				flag = order[flag];
			}
		}
		if (count == 5) {
			state = 0;
			cout << setfill('0') << setw(3) << hour << ' '<<name<<" headquarter stops making warriors" << endl;
		}
	}
int main() {
	int casenum = 0;
	cin >> casenum;
	hour = 0;
	int initenergy = 0;
	for (int z = 0; z < casenum; z++) {
		cin >> initenergy;
		for (int i = 0; i < 5; i++)
			cin >> hp[i];
		cout << "Case:" << z + 1 << endl;
		headquarter red(initenergy, 2, 0, 3, 4, 1, "red", 2);
		headquarter blue(initenergy,1,2,4,0,3,"blue",3);
		while (red.state != 0 || blue.state != 0) {
			if (red.state != 0)
				red.produce();
			if (blue.state != 0)
				blue.produce();
			hour++;
				}
		hour = 0;
			}
    return 0;
}