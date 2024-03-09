#include <iostream>
#include <queue>
using namespace std;

int nx[4] = { 1, 0, -1, 0 };
int ny[4] = { 0, 1, 0, -1 };

int M, N;
int ans;
int field[51][51];
bool visit[51][51];

void Reset()
{
	ans = 0;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			field[i][j] = 0;
			visit[i][j] = false;
		}
	}
}

void BFS(int Y, int X)
{
	ans++;
	queue<pair<int, int>> q;
	q.push({ Y, X });
	visit[Y][X] = true;

	while (!q.empty())
	{
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int _x = x + nx[i];
			int _y = y + ny[i];

			if (_x < 0 || _x >= M || _y < 0 || _y >= N)
				continue;
			if (field[_y][_x] != 1 || visit[_y][_x])
				continue;

			q.push({ _y, _x });
			visit[_y][_x] = true;
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;

	while (T--)
	{
		int K;
		cin >> M >> N >> K;
		
		Reset();
		
		while (K--)
		{
			int x, y;
			cin >> x >> y;
			field[y][x] = 1;
		}

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (field[i][j] == 1 && !visit[i][j])
					BFS(i, j);
			}
		}

		cout << ans << "\n";
	}
}