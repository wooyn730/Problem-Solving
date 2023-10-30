#include <iostream>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, cnt = 0;
	cin >> N;

	for (int i = 5; i <= N; i += 5)
	{
		int n = i;
		while (n % 5 == 0)
		{
			cnt++;
			n /= 5;
		}
	}

	cout << cnt;
}