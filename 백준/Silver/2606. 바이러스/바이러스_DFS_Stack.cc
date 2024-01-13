#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> com[101];
bool virus[101];
int ans;

void DFS(int start)
{
	stack<int> s;
	virus[start] = true;
	s.push(start);

	while (!s.empty())
	{
		int now = s.top();
		s.pop();

		for (int i = 0; i < com[now].size(); i++)
		{
			int next = com[now][i];

			if (!virus[next])
			{
				virus[next] = true;
				s.push(now);
				s.push(next);
				ans++;
				break;
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

	DFS(1);

	cout << ans;
}
