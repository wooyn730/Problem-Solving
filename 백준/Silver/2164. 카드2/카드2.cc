#include <iostream>
#include <string>
#include <queue>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	queue<int> queue;
	int N;
	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		queue.push(i);
	}

	while (true)
	{
		if (queue.size() == 1)
		{
			cout << queue.front();
			break;
		}
		
		queue.pop();
		queue.push(queue.front());
		queue.pop();
	}

	return 0;
}