#include <iostream>
using namespace std;

int arr[100000];
int dp[100000];

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	int ans = arr[0];
	dp[0] = arr[0];

	for (int i = 1; i < n; i++)
	{
		dp[i] = max(dp[i - 1] + arr[i], arr[i]);
		ans = max(dp[i], ans);
	}

	cout << ans;
}