#include <iostream>
using namespace std;

long long dp[101][10]; // dp[i][j] : i자리 수 계단 수 중에 맨 끝이 j인 수의 개수

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	for (int i = 1; i <= 9; i++)
		dp[1][i] = 1;

	for (int i = 2; i <= N; i++)
	{
		// 맨 끝이 0이나 9라면 바로 앞에 올 수 있는 수는 하나뿐
		dp[i][0] = dp[i - 1][1] % 1000000000;
		dp[i][9] = dp[i - 1][8] % 1000000000;

		for (int j = 1; j <= 8; j++)
		{
			dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j + 1] % 1000000000;
		}
	}

	long long ans = 0;
	for (int i = 0; i <= 9; i++)
	{
		ans += dp[N][i];
		ans %= 1000000000;
	}

	cout << ans;
}