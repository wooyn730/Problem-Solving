#include <iostream>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t = 5, sum = 0, num;
	while (t--)
	{
		cin >> num;

		sum += num < 40 ? 40 : num;
	}

	cout << sum / 5;
}