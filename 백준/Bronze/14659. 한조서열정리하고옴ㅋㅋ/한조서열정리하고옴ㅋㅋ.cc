#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;
	vector<int> mountain(N);
	int best = 0;

	for (int i = 0; i < N; i++)
		cin >> mountain[i];

	for (int i = 0; i < N - 1; i++) // 용 발사
	{
		int tmp = 0;
		for (int j = i+1; j < N; j++) // 용이 적 처치
		{
			if (mountain[i] >= mountain[j])
				tmp++;
			else
				break;
		}
		if (tmp > best)
			best = tmp;
	}

	cout << best;
	return 0;
}