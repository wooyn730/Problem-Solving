#include <iostream>
#include <vector>
using namespace std;

int N, ans;
vector<pair<int, int>> ingredient;
bool selected[10];
vector<int> selectedIdx;

void Init()
{
	selectedIdx.clear();
	for (int i = 0; i < N; i++)
		selected[i] = false;
}

void DFS(int size, int cnt) // 뽑을 개수, 뽑은 개수
{
	if (cnt == size)
	{
		int s1 = 1, b2 = 0;
		for (int i = 0; i < selectedIdx.size(); i++)
		{
			s1 *= ingredient[selectedIdx[i]].first;
			b2 += ingredient[selectedIdx[i]].second;
		}
		int cook = (s1 - b2 > 0 ? s1 - b2 : b2 - s1);
		ans = (ans > cook ? cook : ans);
		return;
	}

	for (int i = 0; i < N; i++)
	{
		if (selected[i])
			continue;
		selected[i] = true;
		selectedIdx.push_back(i);
		DFS(size, cnt + 1);
		selectedIdx.pop_back();
		selected[i] = false;
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	int s1 = 1, b2 = 0;

	for (int i = 0; i < N; i++)
	{
		int s, b;
		cin >> s >> b;
		ingredient.push_back({ s, b });
		s1 *= s;
		b2 += b;
		ans = (s1 - b2 > 0 ? s1 - b2 : b2 - s1);
	}

	for (int i = 1; i < N; i++)
	{
		// 1개부터 N개까지의 재료를 뽑아서 요리
		Init();
		DFS(i, 0);
	}

	cout << ans;
}