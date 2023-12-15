#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int N;
	cin >> N;

	vector<int> distance(N - 1);
	for (int i = 0; i < N - 1; i++)
		cin >> distance[i];

	long long ans = 0, nowPrice, lowPrice;
	for (int i = 0; i < N; i++)
	{
		cin >> nowPrice;

		if (i == N - 1)
			break;

		if (i == 0 || nowPrice < lowPrice)
			lowPrice = nowPrice;

		ans += lowPrice * distance[i];
	}

	cout << ans;
}