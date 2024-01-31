#include <iostream>
using namespace std;

int N, M, r, c, d;
int room[51][51]; // 0 안치움 1 벽 2 치움

// d: 0북 1동 2남 3서
int nx[4] = { -1, 0, 1, 0 };
int ny[4] = { 0, 1, 0, -1 };
int clean;

void RoboticVacuum(int x, int y, int d)
{
	if (room[x][y] == 0)
	{
		room[x][y] = 2;
		clean++;
	}

	bool isBlank = false;
	for (int i = 0; i < 4; i++)
	{
		int _d = (d + 3 - i) % 4;
		int _x = x + nx[_d];
		int _y = y + ny[_d];

		if (_x >= 0 && _x <= N - 1 && _y >= 0 && _y <= M - 1)
		{
			if (room[_x][_y] == 0)
			{
				RoboticVacuum(_x, _y, _d);
				isBlank = true;
				break;
			}
		}
	}

	if (!isBlank)
	{
		// 뒤가 벽이 아니라면 후진
		int _d = (d + 2) % 4;
		int _x = x + nx[_d];
		int _y = y + ny[_d];

		if (_x >= 0 && _x <= N - 1 && _y >= 0 && _y <= M - 1)
		{
			if (room[_x][_y] != 1)
				RoboticVacuum(_x, _y, d);
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> N >> M >> r >> c >> d;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> room[i][j];

	RoboticVacuum(r, c, d);

	cout << clean;
}