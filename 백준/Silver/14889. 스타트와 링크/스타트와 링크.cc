#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int N;
int S[21][21];
bool selected[21];
int minAns = 9999;

void DFS(int idx, int cnt)
{
	if (cnt == N / 2)
	{
		int startTeam = 0;
		int linkTeam = 0;
		for (int i = 0; i < N - 1; i++)
		{
			for (int j = i + 1; j < N; j++)
			{
				if (selected[i] && selected[j])
					startTeam += S[i][j] + S[j][i];
				else if (!selected[i] && !selected[j])
					linkTeam += S[i][j] + S[j][i];
			}
		}

		int diff = abs(startTeam - linkTeam);
		minAns = (diff < minAns ? diff : minAns);
	}

	for (int i = idx + 1; i < N; i++)
	{
		if (selected[i])
			continue;
		selected[i] = true;
		DFS(i, cnt + 1);
		selected[i] = false;
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> S[i][j];

	DFS(0, 0);

	cout << minAns;
}