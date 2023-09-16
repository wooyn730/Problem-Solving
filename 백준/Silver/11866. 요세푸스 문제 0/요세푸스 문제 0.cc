#include <iostream>
#include <string>
#include <queue>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	queue<int> queue;
	int N, K;
	cin >> N >> K;

	for (int i = 1; i <= N; i++)
	{
		queue.push(i);
	}

	cout << "<";
	while (true)
	{
		for (int i = 1; i <= K; i++)
		{
			if (i == K)
				cout << queue.front();
			else
				queue.push(queue.front());

			queue.pop();
		}

		if (!queue.size())
			break;
		else
			cout << ", ";
	}
	cout << ">";
	return 0;
}