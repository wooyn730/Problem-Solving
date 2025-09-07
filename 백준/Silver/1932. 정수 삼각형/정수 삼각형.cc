#include <iostream>
#include <algorithm>
using namespace std;

int n, dp[505][505];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < i+1; j++)
		{
			cin >> dp[i][j];
		}
	}

	// dp[1][1] == 7
	// dp[2][1] == 3   dp[2][2] == 8


	for (int i = n-1; i >= 1; i--) // 아래에서부터 큰수를 선택해 더함
	{
		for (int j = 0; j < i; j++)
		{
			dp[i-1][j] += max(dp[i][j], dp[i][j+1]);
		}
	}
	

	cout << dp[0][0];
}