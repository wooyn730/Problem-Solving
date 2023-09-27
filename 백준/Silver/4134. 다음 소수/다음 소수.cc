#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;

	while (T--)
	{
		long long n;
		cin >> n;
		if (n <= 2)
			cout << 2 << "\n";
		else
		{
			for (long long i = n; ; i++)
			{
				bool isPrime = true;
				for (long long j = 2; j <= sqrt(i); j++)
				{
					if (i % j == 0)
					{
						isPrime = false;
						break;
					}
				}
				if (isPrime)
				{
					cout << i << "\n";
					break;
				}
			}
		}
	}

	return 0;
}