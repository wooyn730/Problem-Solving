#include <iostream>
using namespace std;

int N, S, ans;
int numbers[21];

void FindSum(int sum, int idx)
{
	if (idx == N - 1)
	{
		if (sum == S)
			ans++;
		
		return;
	}

	FindSum(sum + numbers[idx + 1], idx + 1);
	FindSum(sum, idx + 1);
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> S;
	for (int i = 0; i < N; i++)
		cin >> numbers[i];
	
	FindSum(0, -1);

	if (S == 0) // 목표 0일 때 공집합 제외
		ans--;

	cout << ans;
}