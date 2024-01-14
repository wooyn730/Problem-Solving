#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> com[101];
bool virus[101];
int ans;

void BFS(int start)
{
	queue<int> q;
	virus[start] = true;
	q.push(start);

	while (!q.empty())
	{
		int now = q.front();
		q.pop();

		for (int i = 0; i < com[now].size(); i++)
		{
			int next = com[now][i];

			if (!virus[next])
			{
				virus[next] = true;
				q.push(next);
				ans++;
			}
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int computer, T;
	cin >> computer >> T;

	while (T--)
	{
		int a, b;
		cin >> a >> b;
		com[a].push_back(b);
		com[b].push_back(a);
	}

	BFS(1);

	cout << ans;
}
