#include <iostream>
using namespace std;

int wine[10001];
int dp[10001];

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)
		cin >> wine[i];

	dp[0] = 0;
	dp[1] = wine[1];
	dp[2] = wine[1] + wine[2];

	for (int i = 3; i <= n; i++)
	{
		dp[i] = max(max(dp[i - 3] + wine[i - 1] + wine[i], dp[i - 2] + wine[i]), dp[i - 1]);
		// Oxoo Oxo Ox
	}

	cout << dp[n];
}