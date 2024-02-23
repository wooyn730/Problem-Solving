#include <iostream>
#include <vector>
using namespace std;

int N, M;
int city[51][51];
vector<pair<int, int>> house;
vector<pair<int, int>> chicken;
vector<pair<int, int>> selectedChicken;
bool selected[14];
int ans;

void SelectChicken(int idx, int cnt)
{
	if (cnt == M)
	{
		int sum = 0;
		for (int i = 0; i < house.size(); i++)
		{
			int shortest = 0;
			for (int j = 0; j < selectedChicken.size(); j++)
			{
				int distance = abs(house[i].first - selectedChicken[j].first)
					+ abs(house[i].second - selectedChicken[j].second);

				shortest = (shortest == 0 ? distance : (distance < shortest ? distance : shortest));
			}
			sum += shortest;
		}
		
		ans = (ans == 0 ? sum : (sum < ans ? sum : ans));
		return;
	}

	for (int i = idx + 1; i < chicken.size(); i++)
	{
		if (selected[i])
			continue;
		selected[i] = true;
		selectedChicken.push_back({ chicken[i].first, chicken[i].second });
		SelectChicken(i, cnt + 1);
		selected[i] = false;
		selectedChicken.pop_back();
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> city[i][j];
			if (city[i][j] == 1)
				house.push_back({ i, j });
			else if (city[i][j] == 2)
				chicken.push_back({ i, j });
		}
	}

	if (chicken.size() == M)
		selectedChicken = chicken;
	SelectChicken(-1, selectedChicken.size());

	cout << ans;
}