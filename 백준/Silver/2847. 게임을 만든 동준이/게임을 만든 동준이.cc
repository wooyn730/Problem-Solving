#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	int N;
	cin >> N;
	int score[101];
	for (int i = 0; i < N; i++)
		cin >> score[i];

	int down = 0;
	for (int i = N - 1; i > 0; i--)
	{
		if (score[i - 1] >= score[i])
		{
			int m = score[i - 1] - score[i] + 1;
			down += m;
			score[i - 1] -= m;
		}
	}
	
	cout << down;
	return 0;
}