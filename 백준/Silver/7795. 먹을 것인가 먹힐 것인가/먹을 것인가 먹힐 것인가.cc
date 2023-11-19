#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T, N, M, cnt;
	cin >> T;

	while (T--)
	{
		cnt = 0;
		cin >> N >> M;
		vector<int> a(N);
		vector<int> b(M);

		for (int i = 0; i < N; i++)
			cin >> a[i];
		sort(a.begin(), a.end());

		for (int i = 0; i < M; i++)
			cin >> b[i];
		sort(b.begin(), b.end());

		for (int i = 0; i < M; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (a[j] > b[i])
				{
					cnt += N - j;
					break;
				}
			}
		}

		cout << cnt << "\n";
	}
}