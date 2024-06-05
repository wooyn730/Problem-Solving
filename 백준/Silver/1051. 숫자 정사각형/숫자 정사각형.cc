#include <iostream>
using namespace std;

int N, M;
int rect[51][51];
int ans = 1;

void GetSquare(int i, int j, int size)
{
	int plus = size - 1;
	if (i + plus >= N || j + plus >= M)
		return;

	if (rect[i][j] == rect[i + plus][j]
		&& rect[i + plus][j] == rect[i][j + plus]
		&& rect[i][j + plus] == rect[i + plus][j + plus])
	{
		ans = max(ans, size);
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;
	cin.ignore();
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			char c = cin.get();

			if (c == '\n')
				c = cin.get();

			rect[i][j] = c - '0';
		}
	}

	// 정사각형의 크기는 1부터 N과 M 중 작은 수의 제곱이 될 수 있다.
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			for (int k = 2; k <= min(N, M); k++)
			{
				GetSquare(i, j, k);
			}
		}
	}

	cout << ans * ans;
}