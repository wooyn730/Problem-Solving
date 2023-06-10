#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	int N, M;
	cin >> N >> M;
	vector<string> DNA(N);

	for (int i = 0; i < N; i++)
		cin >> DNA[i];
	
	string tmp = "";
	int diff = 0;

	for (int i = 0; i < M; i++)
	{
		int a[26] = {0};
		for (int j = 0; j < N; j++)
		{
			a[DNA[j][i] - 65]++;
		}
		
		int max = 0;
		int maxIdx = 0;
		for (int j = 0; j < 26; j++)
		{
			if (a[j] > max)
			{
				max = a[j];
				maxIdx = j;
			}
		}
		for (int j = 0; j < 26; j++)
		{
			if (j != maxIdx)
			{
				diff += a[j];
			}
		}

		tmp += (char)(maxIdx + 65);
	}
	
	cout << tmp << endl << diff;
	return 0;
}