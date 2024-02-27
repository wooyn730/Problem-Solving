#include <iostream>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, F, ans = 0;
	cin >> N >> F;

	N -= (N % 100);

	for (int i = 0; i <= 99; i++)
	{
		if ((N + i) % F == 0)
		{
			ans = i;
			break;
		}
	}
	cout << (ans < 10 ? "0" : "") << ans;
}