#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t, n;
	cin >> t;

	while (t--)
	{
		cin >> n;

		// 집, 편의점, 축제 가능하면 모두 잇는다
		// 집과 축제가 이어지는지 bfs/dfs로 찾기
		vector<pair<int, int>> stuff;

		for (int i = 0; i < n + 2; i++)
		{
			int x, y;
			cin >> x >> y;
			stuff.push_back({ x, y });
		}

		vector<int> link[102];
		bool visit[102] = { false };
			
		for (int i = 0; i < stuff.size() - 1; i++)
		{
			for (int j = i + 1; j < stuff.size(); j++)
			{
				int x = stuff[i].first - stuff[j].first;
				int y = stuff[i].second - stuff[j].second;
				int dis = (x >= 0 ? x : -x) + (y >= 0 ? y : -y);

				if (dis <= 1000)
				{
					// 연결을 어떻게? stuff의 인덱스로
					link[i].push_back(j);
					link[j].push_back(i);
				}
			}
		}

		bool isHappy = false;
		queue<pair<pair<int, int>, int>> q;
		q.push({ {stuff[0].first, stuff[0].second }, 0 });
		visit[0] = true;
		while (!q.empty())
		{
			int x = q.front().first.first;
			int y = q.front().first.second;
			int idx = q.front().second;
			q.pop();

			if (x == stuff[stuff.size() - 1].first && y == stuff[stuff.size() - 1].second)
			{
				isHappy = true;
				break;
			}

			for (int i = 0; i < link[idx].size(); i++)
			{
				int nidx = link[idx][i];
				int nx = stuff[nidx].first;
				int ny = stuff[nidx].second;

				if (!visit[nidx])
				{
					q.push({ {nx, ny}, nidx });
					visit[nidx] = true;
				}
			}
		}

		cout << (isHappy ? "happy\n" : "sad\n");
	}
}