#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	int n, cnt = 0;
	cin >> n;

	while (true)
	{
		if (n % 5 == 0)
		{
			cnt += n / 5;
			break;
		}
		else
		{
			n -= 2;
			cnt++;
		}

		if (n < 0)
		{
			cout << -1;
			return 0;
		}
	}
	cout << cnt;
	return 0;
}