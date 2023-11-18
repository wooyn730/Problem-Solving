#include <iostream>
#include <algorithm>
using namespace std;

int T, N, M, note1[10000001], note2[10000001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;

	while (T--)
	{
		cin >> N;
		for (int i = 0; i < N; i++)
			cin >> note1[i];

		sort(note1, note1 + N);

		cin >> M;
		for (int i = 0; i < M; i++)
			cin >> note2[i];


		for (int i = 0; i < M; i++)
		{
			bool flag = false;
			int left = 0;
			int right = N - 1;

			while (left <= right)
			{
				int mid = (left + right) / 2;
				if (note2[i] == note1[mid])
				{
					flag = true;
					break;
				}
				if (note2[i] > note1[mid])
					left = mid + 1;
				else
					right = mid - 1;
			}

			if (flag)
				cout << 1 << '\n';
			else
				cout << 0 << '\n';
		}
	}
}