#include <iostream>;
using namespace std;
int main() {
	int rankboyang, rankdongting, ranktaihu, rankhongze = 0;
	for (rankboyang = 1; rankboyang <= 4; rankboyang++) {
		for (rankdongting = 1; rankdongting <= 4; rankdongting++) {
			for (ranktaihu = 1; ranktaihu <= 4; ranktaihu++) {
				for (rankhongze = 1; rankhongze <= 4; rankhongze++) {
					bool a1 = rankdongting == 1;
					bool a2 = rankhongze == 4;
					bool a3 = rankboyang == 3;
					bool b1 = rankhongze == 1;
					bool b2 = rankboyang == 2;
					bool b3 = ranktaihu == 3;
					bool b4 = rankdongting == 4;
					bool c1 = rankdongting == 3;
					bool c2 = rankhongze == 4;
					bool d1 = rankboyang == 1;
					bool d2 = rankhongze == 2;
					bool d3 = rankdongting == 3; 
					bool d4 = ranktaihu == 4;
					if (a1 + a2 + a3 == 1 && b1 + b2 + b3 + b4 == 1 && c1 + c2 == 1 && d1 + d2 + d3 + d4 == 1&&rankboyang!=rankdongting&&rankboyang!=rankhongze&&rankboyang!=ranktaihu&&rankdongting!=rankhongze&&rankdongting!=ranktaihu&&rankhongze!=ranktaihu) {
						cout << rankboyang << endl;
						cout << rankdongting << endl;
						cout << ranktaihu << endl;
						cout << rankhongze << endl;
					}
				}
			}
		}
	}
	return 0;
}