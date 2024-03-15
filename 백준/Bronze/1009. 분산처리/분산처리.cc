#include <iostream>
#include <cmath>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;

	while (T--)
	{
		int a, b;
		cin >> a >> b;

		a %= 10;
		b = b % 4 + 4;

		int c = pow(a, b);
		c %= 10;

		cout << (c == 0 ? 10 : c) << "\n";
	}
}