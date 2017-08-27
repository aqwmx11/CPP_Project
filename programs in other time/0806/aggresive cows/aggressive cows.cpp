#include <iostream>;
#include <stdio.h>;
#include <cstdlib>;
using namespace std;
int stall[100002];
int N, C;
int cmp(const void *x, const void *y){
	return *(int *)x - *(int *)y;
}
bool greed(int x) {
	int count = C-1;
	int temp = 0;
	while (count > 0) {
		int flag = 0;
		for (int i = temp + 1; i <= N; i++) {
			if (stall[i] - stall[temp] >= x) {
				flag = 1;
				temp = i;
				count--;
				continue;
			}
		}
		if (flag == 0) {
			return false;
			break;
		}
	}
	return true;
}
int main() {
	scanf("%d%d", &N, &C);
	for (int i = 0; i < N; i++)
		scanf("%d", &stall[i]);
	qsort(stall, N, sizeof(int), cmp);
	int left, mid, right;
	left = 0;
	right = (stall[N - 1] - stall[0]) / (C - 1);
	while (left <= right) {
		mid = (left + right) / 2;
		if (greed(mid))
			left = mid + 1;
		else
			right = mid - 1;
	}
	printf("%d\n", left - 1);
	return 0;
}