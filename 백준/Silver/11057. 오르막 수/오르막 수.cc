#include <iostream>
using namespace std;

int cnt[1001][10]; // 자릿수, 숫자

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, ans = 0;
	cin >> N;

	for (int i = 0; i < 10; i++)
	{
		cnt[1][i] = 1;
	}

	for (int i = 2; i <= N; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			for (int k = 0; k <= j; k++)
			{
				cnt[i][j] += cnt[i - 1][k];
			}
			cnt[i][j] %= 10007;
		}
	}

	for (int i = 0; i < 10; i++)
	{
		ans += cnt[N][i];
	}

	cout << ans % 10007;
}