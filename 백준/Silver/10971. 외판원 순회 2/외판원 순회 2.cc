#include <iostream>
#include <vector>
using namespace std;

int N, ans = 10000000;
int W[11][11];
bool visit[11];
vector<int> vec;

void DFS(int cnt)
{
	if (cnt == N)
	{
		int sum = 0;
		for (int i = 0; i < N; i++)
		{
			int cost = W[vec[i]][(vec[(i + 1) % N])];
			if (cost == 0)
				return;
			sum += cost;
		}
		ans = (sum < ans ? sum : ans);
		return;
	}

	for (int i = 0; i < N; i++)
	{
		if (visit[i])
			continue;
		visit[i] = true;
		vec.push_back(i);
		DFS(cnt + 1);
		visit[i] = false;
		vec.pop_back();
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> W[i][j];

	DFS(0);

	cout << ans;
}