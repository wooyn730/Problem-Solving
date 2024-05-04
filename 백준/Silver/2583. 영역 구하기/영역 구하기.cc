#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int ny[4] = { 0, 1, 0, -1 };
int nx[4] = { 1, 0, -1, 0 };

int M, N, K;
bool paper[101][101];
bool visit[101][101];
vector<int> ans;

void BFS(int y, int x)
{
	ans.push_back(1);
	queue<pair<int, int>> q;
	q.push({ y, x });
	visit[y][x] = true;

	while (!q.empty())
	{
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int _y = y + ny[i];
			int _x = x + nx[i];

			if (_y < M && _y >= 0 && _x < N && _x >= 0)
			{
				if (!visit[_y][_x] && !paper[_y][_x])
				{
					ans[ans.size() - 1]++;
					q.push({ _y, _x });
					visit[_y][_x] = true;
				}
			}
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> M >> N >> K;

	for (int i = 0; i < K; i++)
	{
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;

		for (int k = y1; k < y2; k++)
			for (int j = x1; j < x2; j++)
				paper[k][j] = true;
	}

	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (!visit[i][j] && !paper[i][j])
			{
				BFS(i, j);
			}
		}
	}

	sort(ans.begin(), ans.end());

	cout << ans.size() << "\n";
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << " ";
}