#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, a, b, m;

vector<int> family[101];
bool visit[101];
int ans = -1;

void DFS(int parent, int cnt)
{
	visit[parent] = true;

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
			DFS(children, cnt + 1);
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

	DFS(a, 0);

	cout << ans;
}