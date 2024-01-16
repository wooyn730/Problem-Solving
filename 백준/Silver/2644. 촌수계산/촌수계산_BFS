#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int n, a, b, m;

vector<int> family[101];
bool visit[101];
int ans = -1;

void BFS(int start)
{
	queue<pair<int, int>> q;

	visit[start] = true;
	q.push(make_pair(start, 0));

	while (!q.empty())
	{
		int parent = q.front().first;
		int cnt = q.front().second;
		q.pop();

		if (parent == b)
		{
			ans = cnt;
			return;
		}

		for (int i = 0; i < family[parent].size(); i++)
		{
			int children = family[parent][i];

			if (!visit[children])
			{
				visit[children] = true;
				q.push(make_pair(children, cnt + 1));
			}
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> a >> b >> m;

	while (m--)
	{
		int x, y;
		cin >> x >> y;
		family[x].push_back(y);
		family[y].push_back(x);
	}

	for (int i = 1; i <= n; i++)
	{
		sort(family[i].begin(), family[i].end());
	}

	BFS(a);

	cout << ans;
}
