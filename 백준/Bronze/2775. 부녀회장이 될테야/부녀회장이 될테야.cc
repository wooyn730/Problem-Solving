#include <iostream>
using namespace std;

int apartment(int k, int n)
{
	if (k == 0)
		return n;
	else if (n == 1)
		return 1;
	else
		return apartment(k - 1, n) + apartment(k, n - 1);
}

int main() {
	int T;
	cin >> T;

	while (T--)
	{
		int k, n;
		cin >> k >> n; // k층 n호
		// 0층 1호 = 1명 / 0층 2호 = 2명 / 0층 3호 = 3명
		// 1층 1호 = 1명 / 1층 2호 = 3명 / 1층 3호 = 6명
		// 2층 1호 = 1명 / 2층 2호 = 4명 / 2층 3호 = 10명

		cout << apartment(k, n) << endl;
	}
	return 0;
}