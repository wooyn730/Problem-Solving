#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M, card[100], sM = -1;
	cin >> N >> M;

	for (int i = 0; i < N; i++)
		cin >> card[i];

	for (int i = 0; i < N; i++)
	{
		for (int j = i + 1; j < N; j++)
		{
			for (int k = j + 1; k < N; k++)
			{
				int sum = card[i] + card[j] + card[k];
				if (sum <= M && M - sum < M - sM)
					sM = sum;
			}
		}
	}

	cout << sM;
}