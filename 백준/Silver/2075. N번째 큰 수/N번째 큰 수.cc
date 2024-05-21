#include <iostream>
#include <queue>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	priority_queue<int, vector<int>, greater<int>> pq;

	int N;
	cin >> N;

	for (int i = 0; i < N * N; i++)
	{
		int x;
		cin >> x;

		if (pq.size() < N)
			pq.push(x);
		else if (x > pq.top())
		{
			pq.pop();
			pq.push(x);
		}
	}

	cout << pq.top();
}