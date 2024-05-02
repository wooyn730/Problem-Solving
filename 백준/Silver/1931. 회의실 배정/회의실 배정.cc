#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int>> mt;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, s, e;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> s >> e;
		mt.push_back({ e, s });
	}

	sort(mt.begin(), mt.end());

	int t = mt[0].first;
	int ans = 1;

	for (int i = 1; i < N; i++)
	{
		if (t <= mt[i].second)
		{
			t = mt[i].first;
			ans++;
		}
	}

	cout << ans;
}