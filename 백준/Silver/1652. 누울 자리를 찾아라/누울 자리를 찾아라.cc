#include <iostream>
using namespace std;

bool space[101][101];
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	char c;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> c;
			space[i][j] = (c == 'X' ? false : true);
		}
	}

	int ans1 = 0, ans2 = 0;
	for (int i = 0; i < N; i++)
	{
		int cnt1 = 0, cnt2 = 0;
		for (int j = 0; j < N; j++)
		{
			if (space[i][j])
				cnt1++;
			else
				cnt1 = 0;
			if (cnt1 == 2) ans1++;

			if (space[j][i])
				cnt2++;
			else
				cnt2 = 0;
			if (cnt2 == 2) ans2++;
		}
	}

	cout << ans1 << " " << ans2;
}