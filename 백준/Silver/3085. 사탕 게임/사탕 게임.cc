#include <iostream>
using namespace std;

char candy[51][51];
int N, ans;

void CheckMaxCandy()
{
	for (int i = 0; i < N; i++)
	{
		int cntRow = 1;
		int cntColumn = 1;
		for (int j = 0; j < N; j++)
		{
			if (j < N - 1 && candy[i][j] == candy[i][j + 1])
				cntRow++;
			else
			{
				ans = max(ans, cntRow);
				cntRow = 1;
			}

			if (j < N - 1 && candy[j][i] == candy[j + 1][i])
				cntColumn++;
			else
			{
				ans = max(ans, cntColumn);
				cntColumn = 1;
			}
		}
	}
}

void SwapRow(int i, int j)
{
	if (candy[i][j] == candy[i][j + 1])
		return;

	swap(candy[i][j], candy[i][j + 1]);

	CheckMaxCandy();

	swap(candy[i][j], candy[i][j + 1]);
}

void SwapColumn(int i, int j)
{
	if (candy[j][i] == candy[j + 1][i])
		return;

	swap(candy[j][i], candy[j + 1][i]);

	CheckMaxCandy();

	swap(candy[j][i], candy[j + 1][i]);
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> candy[i][j];

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N - 1; j++)
		{
			SwapRow(i, j);
			SwapColumn(i, j);
		}
	}
	
	cout << ans;
}