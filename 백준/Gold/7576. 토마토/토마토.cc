#include <iostream>
#include <queue>
using namespace std;

queue<pair<pair<int, int>, int>> q;
int M, N, unrape, ans;
int tomato[1001][1001];
bool visit[1001][1001];

int nx[4] = { 1, -1, 0, 0 };
int ny[4] = { 0, 0, 1, -1 };

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> M >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> tomato[i][j];

			switch (tomato[i][j])
			{
			case 0:
				unrape++;
				break;
			case 1:
				q.push({ {i, j}, 0 });
			case -1:
				visit[i][j] = true;
				break;
			}
		}
	}

	while (!q.empty())
	{
		int x = q.front().first.first;
		int y = q.front().first.second;
		int day = q.front().second;
		q.pop();

		ans = (ans > day ? ans : day);

		for (int i = 0; i < 4; i++)
		{
			int _x = x + nx[i];
			int _y = y + ny[i];

			if (_x >= 0 && _x < N && _y >= 0 && _y < M)
			{
				if (visit[_x][_y])
					continue;

				unrape--;
				q.push({ {_x, _y}, day + 1 });
				visit[_x][_y] = true;
			}
		}
	}

	cout << (unrape ? -1 : ans);
}