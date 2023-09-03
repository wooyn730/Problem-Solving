#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N, K;
	cin >> N >> K;

	int cnt = 0;
	for (int i = 1; ; i++)
	{
		if (N % i == 0)
			cnt++;

		if (cnt == K)
		{
			cout << i;
			break;
		}
			
		if (i >= N)
		{
			cout << 0;
			break;
		}
	}
	return 0;
}