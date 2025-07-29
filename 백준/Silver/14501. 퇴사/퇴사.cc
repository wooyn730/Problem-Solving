#include <iostream>
#include <algorithm>
using namespace std;

int N, T[16], P[16], ans;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N;
	
	for (int i = 1; i <= N; i++)
	{
		cin >> T[i] >> P[i];
	}
	
	for (int i = N; i >= 1; i--)
	{
		if (i + T[i] > N + 1)
			P[i] = P[i + 1];
		else
		{
			P[i] = max(P[i + 1], P[i] + P[i + T[i]]);
			ans = max(ans, P[i]);
		}
	}
	cout << ans;
}