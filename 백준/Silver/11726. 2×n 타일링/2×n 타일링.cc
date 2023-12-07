#include <iostream>
using namespace std;

int tiling[1001];

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
;
	int n;
	cin >> n;

	tiling[1] = 1;
	tiling[2] = 2;
	for (int i = 3; i <= n; i++)
		tiling[i] = (tiling[i - 1] + tiling[i - 2]) % 10007;

	cout << tiling[n];
}