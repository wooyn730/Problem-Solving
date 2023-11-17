#include <iostream>
using namespace std;

int dp[11];

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T, n;
	cin >> T;

	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;

	while (T--)
	{
		cin >> n;
		for (int i = 4; i <= n; i++)
		{
			if (dp[i] == 0)
				dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
		}
		cout << dp[n] << "\n";
	}
}