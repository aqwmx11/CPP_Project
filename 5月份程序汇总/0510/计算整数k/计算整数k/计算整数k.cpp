#include <iostream>
using namespace std;

int main()
{
	int counts;
	cin >> counts;
	while (counts--)
	{
		int n, i, j;
		cin >> n >> i >> j;
		int result = 0;
		if (n & (1 << i))
		{
			result |= 1 << i;
		}
		if (!(n & (1 << j)))
		{
			result |= 1 << j;
		}
		for (int k = i + 1; k < j; k++)
		{
			result |= 1 << k;
		}
		cout << hex << result << endl;
	}
	return 0;
}