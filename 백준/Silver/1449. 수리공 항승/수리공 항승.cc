#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, bool>> hole;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int ans = 0;
	int N, L;
	cin >> N >> L;

	for (int i = 0; i < N; i++)
	{
		int x;
		cin >> x;
		hole.push_back({ x, false });
	}

	sort(hole.begin(), hole.end());

	for (int i = 0; i < N; i++)
	{
		if (hole[i].second)
			continue;

		ans++;
		float tapeEnd = hole[i].first - 0.5f + L;

		int j = 1;
		while (i + j < N)
		{
			if (hole[i + j].first <= tapeEnd - 0.5f)
				hole[i + j].second = true;
			else
				break;
			j++;
		}
	}

	cout << ans;
}