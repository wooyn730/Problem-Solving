#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int nx[6] = { 1, -1, 0, 0, 0, 0 };
int ny[6] = { 0, 0, 1, -1, 0, 0 };
int nz[6] = { 0, 0, 0, 0, 1, -1 };

typedef struct {
	int x, y, z;
	int day;
}pos;

int tomato[101][101][101];
bool visit[101][101][101];
int unrape, ans = -1;

queue<pos> q;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int M, N, H;
	cin >> M >> N >> H;

	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < M; k++)
			{
				cin >> tomato[i][j][k];

				if (tomato[i][j][k] == 1)
				{
					q.push({ i, j, k, 0 });
					visit[i][j][k] = true;
				}
				else if (tomato[i][j][k] == -1)
					visit[i][j][k] = true;
				else
					unrape++;
			}
		}
	}

	while (!q.empty())
	{
		int x = q.front().x;
		int y = q.front().y;
		int z = q.front().z;
		int day = q.front().day;
		q.pop();

		ans = max(ans, day);

		for (int i = 0; i < 6; i++)
		{
			int _x = x + nx[i];
			int _y = y + ny[i];
			int _z = z + nz[i];

			// 범위 체크
			if (!(_x >= 0 && _x < H && _y >= 0 && _y < N && _z >= 0 && _z < M))
				continue;

			if (!visit[_x][_y][_z]) // 방문 X == 안익음
			{
				unrape--;
				q.push({ _x, _y, _z, day + 1 });
				visit[_x][_y][_z] = true;
			}
		}
	}

	cout << (unrape ? -1 : ans);
}