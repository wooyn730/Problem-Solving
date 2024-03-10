#include <iostream>
using namespace std;

int dp[1000][3];

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	for (int j = 0; j < 3; j++)
		cin >> dp[0][j];

	for (int i = 1; i < N; i++)
	{
		for (int j = 0; j < 3; j++)
			cin >> dp[i][j];

		dp[i][0] += min(dp[i - 1][1], dp[i - 1][2]);
		dp[i][1] += min(dp[i - 1][0], dp[i - 1][2]);
		dp[i][2] += min(dp[i - 1][0], dp[i - 1][1]);
	}
	cout << min(dp[N - 1][0], min(dp[N - 1][1], dp[N - 1][2]));
}