#include <iostream>
using namespace std;

int main() {
	int N, ans=0;
	cin >> N;

	for (int i = 1; i < N; i++)
	{
		int num = i, sum = i;
		while (num)
		{
			sum += num % 10;
			num /= 10;
		}

		if (sum == N)
		{
			ans = i;
			break;
		}
			
	}
	cout << ans;
	return 0;
}