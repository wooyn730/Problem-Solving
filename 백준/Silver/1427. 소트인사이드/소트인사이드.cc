#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int nums[10] = { 0 };

	int N;
	cin >> N;

	while (N != 0)
	{
		nums[N % 10]++;
		N /= 10;
	}

	for (int i = 9; i >= 0; i--)
	{
		while (nums[i]-- != 0)
			cout << i;
	}

	return 0;
}