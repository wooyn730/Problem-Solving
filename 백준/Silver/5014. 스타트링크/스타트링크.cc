#include <iostream>
#include <queue>
using namespace std;

bool visit[1000001];

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int F, S, G, U, D;
	cin >> F >> S >> G >> U >> D;

	queue<pair<int, int>> q;
	q.push({ S, 0 });
	visit[S] = true;

	while (!q.empty())
	{
		int now = q.front().first;
		int cnt = q.front().second;
		q.pop();

		if (now == G)
		{
			cout << cnt;
			return 0;
		}

		int up = now + U;
		int down = now - D;

		if (up <= F && !visit[up])
		{
			q.push({ up, cnt + 1 });
			visit[up] = true;
		}
		if (down >= 1 && !visit[down])
		{
			q.push({ down, cnt + 1 });
			visit[down] = true;
		}
	}

	cout << "use the stairs";
}