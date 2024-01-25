#include <iostream>
#include <vector>
using namespace std;

int N;
bool height[101];
bool visit[101][101];

int origin_region[101][101];
bool simul_region[101][101];

int safezone, max_safezone = 1;

int nx[4] = { 0, 1, 0, -1 };
int ny[4] = { 1, 0, -1, 0 };

void DFS(int x, int y)
{
	visit[x][y] = true;

	for (int i = 0; i < 4; i++)
	{
		int _x = x + nx[i];
		int _y = y + ny[i];

		if (_x >= 0 && _x < N && _y >= 0 && _y < N)
			if (simul_region[_x][_y] && !visit[_x][_y])
				DFS(_x, _y);
	}
}

void Simulation(int rain)
{
	if (safezone > max_safezone)
		max_safezone = safezone;
	safezone = 0;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			visit[i][j] = false;
			simul_region[i][j] = (origin_region[i][j] - rain > 0 ? true : false);
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> origin_region[i][j];

			if (!height[origin_region[i][j]])
				height[origin_region[i][j]] = true;
		}
	}

	for (int i = 0; i < 101; i++)
	{
		if (height[i])
			Simulation(i);

		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < N; k++)
			{
				if (simul_region[j][k] && !visit[j][k])
				{
					DFS(j, k);
					safezone++;
				}
			}
		}
	}

	cout << max_safezone;
}
