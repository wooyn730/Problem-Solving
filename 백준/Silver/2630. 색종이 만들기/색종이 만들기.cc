#include <iostream>
using namespace std;

// 분할정복
int n, paper[128][128], blue, white;
	// 2 ~ 128

void solve(int y, int x, int size)
{
	int check = paper[y][x];
	for (int i = y; i < y + size; i++)
	{
		for (int j = x; j < x + size; j++)
		{
			if (check == 0 && paper[i][j] == 1)
				check = 2;
			else if (check == 1 && paper[i][j] == 0)
				check = 2;

			if (check == 2)
			{
				solve(y, x, size / 2); // 왼 위
				solve(y, x + size / 2, size / 2); // 오 위
				solve(y + size / 2, x, size / 2); // 왼 아
				solve(y + size / 2, x + size / 2, size / 2); // 오 아
				return;
			}
		}
	}
	if (check == 0)
		white++;
	else
		blue++;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cin >> paper[i][j];
	}

	solve(0, 0, n);
	cout << white << '\n' << blue << '\n';
}