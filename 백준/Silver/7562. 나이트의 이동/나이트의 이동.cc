#include <iostream>
#include <queue>
using namespace std;

int nx[8] = { 2, 2, -2, -2, 1, 1, -1, -1 };
int ny[8] = { 1, -1, 1, -1, 2, -2, 2, -2 };

bool visit[301][301];
int l, sx, sy, ex, ey;

int BFS()
{
	queue<pair<pair<int, int>, int>> q;
	q.push({ { sx, sy }, 0 });
	visit[sx][sy] = true;

	while (!q.empty())
	{
		int x = q.front().first.first;
		int y = q.front().first.second;
		int cnt = q.front().second;
		q.pop();

		if (x == ex && y == ey)
		{
			return cnt;
		}

		for (int i = 0; i < 8; i++)
		{
			int _x = x + nx[i];
			int _y = y + ny[i];

			if (_x < l && _x >= 0 && _y < l && _y >= 0)
			{
				if (!visit[_x][_y])
				{
					q.push({ { _x, _y }, cnt + 1 });
					visit[_x][_y] = true;
				}
			}
		}
	}
}

void init()
{
	for (int i = 0; i < l; i++)
		for (int j = 0; j < l; j++)
			visit[i][j] = false;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;

	while (T--)
	{
		cin >> l >> sx >> sy >> ex >> ey;
		init();
		cout << BFS() << "\n";
	}
}