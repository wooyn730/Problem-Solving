#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int n;
vector<int> nums;

void DFS(int cnt, int size)
{
	if (cnt == size)
	{
		int sum = 0;
		for (int i = 0; i < nums.size(); i++)
			sum += pow(nums[i], 2);

		if (sum == n)
		{
			cout << size;
			exit(0);
		}
		return;
	}
	for (int i = 1; i <= sqrt(n); i++)
	{
		nums.push_back(i);
		DFS(cnt + 1, size);
		nums.pop_back();
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	if (pow((int)sqrt(n), 2) == n)
	{
		cout << 1;
		exit(0);
	}

	DFS(0, 2);
	DFS(0, 3);

	cout << 4;
}