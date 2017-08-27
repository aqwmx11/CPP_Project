#include <iostream>;
using namespace std;
int main() {
	int sum = 100;
	int state[9];
	int method[9];
	for (int i = 0; i < 9; i++)
		cin >> state[i];
	for (int i1 = 0; i1 <= 3; i1++) {
		for (int i2 = 0; i2 <= 3; i2++) {
			for (int i3 = 0; i3 <= 3; i3++) {
				for (int i4 = 0; i4 <= 3; i4++) {
					for (int i5 = 0; i5 <= 3; i5++) {
						for (int i6 = 0; i6 <= 3; i6++) {
							for (int i7 = 0; i7 <= 3; i7++) {
								for (int i8 = 0; i8 <= 3; i8++) {
									for (int i9 = 0; i9 <= 3; i9++) {
										if ((i1 + i2 + i4 + state[0]) % 4 == 0 && (i1 + i2 + i3 + i5 + state[1]) % 4 == 0 && (i2 + i3 + i6 + state[2]) % 4 == 0 && (i1 + i4 + i5 + state[3]) % 4 == 0 && (i1 + i3 + i5 + i7 + i9 + state[4]) % 4 == 0 && (i3 + i5 + i6 + i9 + state[5]) % 4 == 0 && (i5 + i7 + i8 + i9 + state[7]) % 4 == 0 && (i4 + i7 + i8 + state[6]) % 4 == 0 && (i6 + i8 + i9 + state[8]) % 4 == 0) {
											if (i1 + i2 + i3 + i4 + i5 + i6 + i7 + i8 + i9 < sum) {
												sum = i1 + i2 + i3 + i4 + i5 + i6 + i7 + i8 + i9;
												method[0] = i1;
												method[1] = i2;
												method[2] = i3;
												method[3] = i4;
												method[4] = i5;
												method[5] = i6;
												method[6] = i7;
												method[7] = i8;
												method[8] = i9;
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	for (int i = 0; i < 9; i++) {
		for (int j = 1; j <= method[i]; j++)
			cout << i + 1 << " ";
	}
	cout << endl;
	return 0;
}