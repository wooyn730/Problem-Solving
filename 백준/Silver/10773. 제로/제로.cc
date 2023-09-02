#include <iostream>
using namespace std;

int num[100000], last = 0;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int K, n;
	cin >> K;

	while (K--)
	{
		cin >> n;
		if (n == 0)
			last--;
		else
			num[last++] = n;
	}

	int sum = 0;
	for (int i = 0; i < last; i++)
		sum += num[i];
	cout << sum;
	return 0;
}