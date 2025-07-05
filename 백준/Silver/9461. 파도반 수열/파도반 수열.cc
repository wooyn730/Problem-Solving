#include <iostream>
#include <algorithm>
using namespace std;

int T, N;
long long dp[101];

long long padoban(int n)
{
	if (n >= 1 && n <= 3)
		return 1;
	if (dp[n] != 0)
		return dp[n];
	else
		dp[n] = padoban(n-2) + padoban(n - 3);

	return dp[n];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> T;

	while (T--)
	{
		cin >> N;
		cout << padoban(N) << '\n';
	}
}