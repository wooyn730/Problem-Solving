#include <iostream>
#include <string>
using namespace std;

int N, Nsize, ans = 0;
bool brokenBtn[10];

void Calculate(int num, int len)
{
	if (num == 0)
		return;
	int tmp = N - num;
	tmp *= (tmp >= 0 ? 1 : -1);
	tmp += len;
	ans = (tmp < ans ? tmp : ans);
}

void DFS(int num)
{
	int len = to_string(num).length();
	if (len == Nsize - 1 || len == Nsize || len == Nsize + 1)
	{
		Calculate(num, len);

		if (len == Nsize + 1)
			return;
	}

	for (int i = 0; i <= 9; i++)
	{
		if (num == 0 && i == 0)
			continue;
		else if (brokenBtn[i])
			continue;
		DFS(num * 10 + i);
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int M;
	cin >> N >> M;

	for (int i = 0; i < M; i++)
	{
		int n;
		cin >> n;
		brokenBtn[n] = true;
	}

	// 100에서 이동 (예외1)
	int tmp = N - 100;
	tmp *= (tmp > 0 ? 1 : -1);
	ans = tmp;

	// BF
	if (M != 10)
	{
		// 0 가능시 0에서 이동 (예외2)
		if (!brokenBtn[0])
		{
			tmp = N + 1;
			ans = (tmp < ans ? tmp : ans);
		}

		Nsize = to_string(N).length();
		DFS(0);
	}

	cout << ans;

	return 0;
}