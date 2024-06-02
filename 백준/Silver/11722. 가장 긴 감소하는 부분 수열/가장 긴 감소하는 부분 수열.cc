#include <iostream>
using namespace std;

int nums[1000];
int len[1000];

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	int ans = 1;
	cin >> nums[0];
	len[0] = 1;

	for (int i = 1; i < N; i++)
	{
		cin >> nums[i];
		int maxValue = 1;

		for (int j = 0; j < i; j++)
		{
			if (nums[i] < nums[j])
				maxValue = max(maxValue, len[j] + 1);
		}

		len[i] = maxValue;
		ans = max(ans, maxValue);
	}

	cout << ans;
}