#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

vector<int> node[1001];
bool visit[1001];

void DFS(int start)
{
	stack<int> s;
	visit[start] = true;
	s.push(start);
	cout << start << " ";

	while (!s.empty())
	{
		int now = s.top();
		s.pop();

		for (int i = 0; i < node[now].size(); i++)
		{
			int next = node[now][i];

			if (!visit[next])
			{
				visit[next] = true;
				s.push(now);
				s.push(next);
				cout << next << " ";
				break;
			}
		}
	}
}

void BFS(int start)
{
	queue<int> q;
	visit[start] = true;
	q.push(start);
	cout << start << " ";

	while (!q.empty())
	{
		int now = q.front();
		q.pop();

		for (int i = 0; i < node[now].size(); i++)
		{
			int next = node[now][i];

			if (!visit[next])
			{
				visit[next] = true;
				q.push(next);
				cout << next << " ";
			}
		}
	}
}

void ResetVisit(int size)
{
	for (int i = 1; i <= size; i++)
		visit[i] = false;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M, V;
	cin >> N >> M >> V;

	while (M--)
	{
		int a, b;
		cin >> a >> b;
		node[a].push_back(b);
		node[b].push_back(a);
	}

	for (int i = 1; i <= N; i++)
	{
		sort(node[i].begin(), node[i].end());
	}

	DFS(V);

	ResetVisit(N);
	cout << "\n";

	BFS(V);
}