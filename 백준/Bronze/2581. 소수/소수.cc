#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int M, N;
	cin >> M >> N;

	int min = -1, sum = 0;

	for (int i = M; i <= N; i++)
	{
		bool isPrime = true;
		if (i == 1)
			isPrime = false;
		else if (i == 2)
			isPrime = true;
		else
		{
			for (int j = 2; j <= sqrt(i); j++)
			{
				if (i % j == 0)
				{
					isPrime = false;
					break;
				}
			}
		}

		if (isPrime)
		{
			if (min == -1)
				min = i;
			sum += i;
		}
	}

	if (min == -1)
		cout << min;
	else
		cout << sum << "\n" << min;

	return 0;
}