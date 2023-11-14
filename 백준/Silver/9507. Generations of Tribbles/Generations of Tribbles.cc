#include <iostream>
using namespace std;

long long koong[70];

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;

	koong[0] = 1;
	koong[1] = 1;
	koong[2] = 2;
	koong[3] = 4;

	for (int i = 4; i < 69; i++)
		koong[i] = koong[i - 1] + koong[i - 2] + koong[i - 3] + koong[i - 4];

	while (t--)
	{
		int num;
		cin >> num;
		cout << koong[num] << "\n";
	}
}