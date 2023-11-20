#include <iostream>
#include <vector>
using namespace std;

int GCD(int a, int b)
{
	return b == 0 ? a : GCD(b, a % b);
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t, n;
	cin >> t;

	while (t--)
	{
		long long sum = 0;
		cin >> n;
		vector<int> num(n);
		for (int i = 0; i < n; i++)
		{
			cin >> num[i];
		}

		for (int i = 0; i < n - 1; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				sum += GCD(num[i], num[j]);
			}
		}

		cout << sum << "\n";
	}
}