#include <iostream>
using namespace std;

int candy[1000][1000];
int maxCandy[1000][1000];

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> candy[i][j];
		}
	}

	maxCandy[0][0] = candy[0][0];

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			int a = 0, b = 0, c = 0;
			if (i - 1 >= 0 && j - 1 >= 0)
				a = maxCandy[i - 1][j - 1];
			if (i - 1 >= 0)
				b = maxCandy[i - 1][j];
			if (j - 1 >= 0)
				c = maxCandy[i][j - 1];

			maxCandy[i][j] = max(max(a, b), c) + candy[i][j];
		}
	}

	cout << maxCandy[N - 1][M - 1];
}