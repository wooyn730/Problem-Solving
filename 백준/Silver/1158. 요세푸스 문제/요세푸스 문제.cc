#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, K;
	cin >> N >> K;
	queue<int> que;
	vector<int> jose;
	
	for (int i = 1; i <= N; i++)
		que.push(i);

	while (!que.empty())
	{
		for (int i = 1; i <= K; i++)
		{
			if (i == K)
				jose.push_back(que.front());
			else
				que.push(que.front());

			que.pop();
		}
	}

	cout << "<";
	for (int i = 0; i < jose.size(); i++)
	{
		cout << jose[i];
		if (i != jose.size() - 1)
			cout << ", ";
	}
	cout << ">";
}