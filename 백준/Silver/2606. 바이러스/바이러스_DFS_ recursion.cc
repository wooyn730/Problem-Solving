#include <iostream>
#include <vector>
using namespace std;

vector<int> com[101];
bool virus[101];
int ans;

void DFS(int x)
{
	for (int i = 0; i < com[x].size(); i++)
	{
		int k = com[x][i];

		if (!virus[k])
		{
			virus[k] = true;
			ans++;
			DFS(k);
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

	virus[1] = true;
	DFS(1);

	cout << ans;
}
