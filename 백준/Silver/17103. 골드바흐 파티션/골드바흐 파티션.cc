#include <iostream>
#include <string>
#include <cmath>
using namespace std;

bool prime[1000001];

void Eratos(int n)
{
	for (int i = n + 1; i <= 1000000; i++)
	{
		if (prime[i] && i % n == 0)
			prime[i] = false;
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	for (int i = 2; i <= 1000000; i++)
	{
		prime[i] = true;
	}
	
	for (int i = 2; i <= sqrt(1000000); i++)
	{
		if (prime[i])
			Eratos(i);
	}

	int N;
	cin >> N;

	while (N--)
	{
		int n, cnt = 0;
		cin >> n;

		for (int i = 2; i <= n / 2; i++)
		{
			if (prime[i] && prime[n - i])
				cnt++;
		}
		cout << cnt << "\n";
	}
}