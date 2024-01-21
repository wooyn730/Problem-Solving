#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool visit[100001];

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, K;
	cin >> N >> K;

	queue<pair<int, int>> q;
	q.push(make_pair(N, 0));
	visit[N] = true;

	while (!q.empty())
	{
		int num = q.front().first;
		int cnt = q.front().second;
		q.pop();

		if (num == K)
		{
			cout << cnt;
			break;
		}

		int nums[3] = { num + 1, num - 1, num * 2 };
		for (int i = 0; i < 3; i++)
		{
			if (nums[i] < 0 || nums[i] > 100000 || visit[nums[i]])
				continue;

			q.push(make_pair(nums[i], cnt + 1));
			visit[nums[i]] = true;
		}
	}
}