#include <iostream>
#include <string>
using namespace std;

// Counting Sort
int nums[100001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, max = 0;
	cin >> N;

	while (N--)
	{
		int num;
		cin >> num;
		if (num > max)
			max = num;
		nums[num]++;
	}
	
	for (int i = 1; i <= max; i++)
	{
		while (nums[i]--)
			cout << i << "\n";
	}
	return 0;
}