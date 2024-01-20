#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int house[26][26];
int visit[26][26];
vector<int> ans;

void DFS(int X, int Y)
{
	visit[X][Y] = ans.size();
	ans[ans.size() - 1]++;

	int nx[4] = { -1, 0, 1, 0 };
	int ny[4] = { 0, -1, 0, 1 };

	for (int i = 0; i < 4; i++)
	{
		int _x = X + nx[i];
		int _y = Y + ny[i];

		if (_x >= 0 && _x < N && _y >= 0 && _y < N)
		{
			if (house[_x][_y] == 1 && visit[_x][_y] == 0)
			{
				DFS(_x, _y);
			}
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		string s;
		cin >> s;

		for (int j = 0; j < N; j++)
			house[i][j] = s[j] - '0';
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (house[i][j] == 1 && visit[i][j] == 0)
			{
				ans.push_back(0);
				DFS(i, j);
			}
		}
	}
	
	sort(ans.begin(), ans.end());

	cout << ans.size();
	for (int i = 0; i < ans.size(); i++)
		cout << "\n" << ans[i];
}