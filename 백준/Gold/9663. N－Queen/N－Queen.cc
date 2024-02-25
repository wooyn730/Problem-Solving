#include <iostream>
#include <vector>
using namespace std;

int N, ans;
int col[15];

void Queen(int x)
{
	if (x == N)
	{
		ans++;
		return;
	}

	for (int i = 0; i < N; i++)
	{
		col[x] = i;
		bool noConflict = true;

		for (int j = 0; j < x; j++)
		{
			if (col[x] == col[j] || abs(col[x] - col[j]) == x - j)
			{
				noConflict = false;
				break;
			}
		}

		if (noConflict)
			Queen(x + 1);
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	Queen(0);
	
	cout << ans;
}