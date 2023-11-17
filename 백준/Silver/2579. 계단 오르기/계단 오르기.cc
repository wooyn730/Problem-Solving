#include <iostream>
using namespace std;

int main() {
	int N;
	int score[301], dp[301];
	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> score[i];
	
	dp[0] = score[0];
	dp[1] = max(score[0], score[0] + score[1]);
	dp[2] = max(score[0] + score[2], score[1] + score[2]);

	if (N >= 3)
	{
		for (int i = 3; i < N; i++)
		{
			// o x o 또는 o x o o
			dp[i] = max(dp[i - 2] + score[i], score[i - 1] + score[i] + dp[i - 3]);
		}
	}

	cout << dp[N - 1];
	return 0;
}