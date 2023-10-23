#include <iostream>
#include <string>
using namespace std;

int num[10000];

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	cin >> N >> M;

	for (int i = 0; i < N; i++)
		cin >> num[i];

	int answer = 0, sum = 0, start = 0, end = 0;
	
	while (end <= N)
	{
		if (sum >= M)
		{
			sum -= num[start++];
		}
		else
		{
			sum += num[end++];
		}

		if (sum == M)
			answer++;
	}

	cout << answer;
}