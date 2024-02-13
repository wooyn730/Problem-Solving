#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int N, ans;
int numbers[8];
bool visit[8];
vector<int> vec;

void DFS(int cnt)
{
	if (cnt == N)
	{
		int sum = 0;
		for (int i = 0; i < vec.size() - 1; i++)
			sum += abs(vec[i] - vec[i + 1]);

		ans = (sum > ans ? sum : ans);
		return;
	}

	for (int i = 0; i < N; i++)
	{
		if (visit[i])
			continue;
		visit[i] = true;
		vec.push_back(numbers[i]);

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
		cin >> numbers[i];

	DFS(0);

	cout << ans;
}