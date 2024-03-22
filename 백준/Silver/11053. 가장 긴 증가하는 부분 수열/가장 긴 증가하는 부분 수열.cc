#include <iostream>
using namespace std;

int arr[1000];
int len[1000];

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, ans = 1;
	cin >> n;

	cin >> arr[0];
	len[0] = 1;

	for (int i = 1; i < n; i++)
	{
		cin >> arr[i];
		int maxVal = 1;

		for (int j = 0; j < i; j++)
			if (arr[j] < arr[i])
				maxVal = max(maxVal, len[j] + 1);

		len[i] = maxVal;
		ans = max(ans, maxVal);
	}

	cout << ans;
}