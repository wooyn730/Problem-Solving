#include <iostream>
#include <queue>
using namespace std;

int ny[4] = { 1, 0, -1, 0 };
int nx[4] = { 0, 1, 0, -1 };

int N, M; // 세로 가로
bool map[50][50];
bool visit[50][50];
int ans;

void BFS(int y, int x)
{
	queue<pair<pair<int, int>, int>> q;
	q.push({ { y, x }, 0 });
	visit[y][x] = true;

	while (!q.empty())
	{
		int Y = q.front().first.first;
		int X = q.front().first.second;
		int cnt = q.front().second;
		q.pop();

		if (cnt > ans)
			ans = cnt;

		for (int i = 0; i < 4; i++)
		{
			int _y = Y + ny[i];
			int _x = X + nx[i];

			if (_y >= 0 && _y < N && _x >= 0 && _x < M)
			{
				if (map[_y][_x] && !visit[_y][_x])
				{
					q.push({ {_y, _x}, cnt + 1 });
					visit[_y][_x] = true;
				}
			}
		}
	}
}

void initVisit()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			visit[i][j] = false;
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			char c;
			cin >> c;
			map[i][j] = (c == 'L');
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (map[i][j])
			{
				initVisit();
				BFS(i, j);
			}
		}
	}

	cout << ans;
}