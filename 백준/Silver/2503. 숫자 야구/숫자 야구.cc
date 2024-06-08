#include <iostream>
#include <vector>
using namespace std;

int N;
int num[100][3];
int check[100][2];

int ans;
vector<int> ball;
bool selected[10];

void DFS(int cnt)
{
	if (cnt == 3)
	{
		for (int i = 0; i < N; i++)
		{
			int s = 0, b = 0;
			for (int j = 0; j < 3; j++)
			{
				if (num[i][j] == ball[j])
					s++;
				if (num[i][j] == ball[(j + 1) % 3] || num[i][j] == ball[(j + 2) % 3])
					b++;
			}
			if (!(check[i][0] == s && check[i][1] == b))
				return;
		}

		ans++;
		return;
	}

	for (int i = 1; i <= 9; i++)
	{
		if (selected[i])
			continue;
		selected[i] = true;
		ball.push_back(i);
		DFS(cnt + 1);
		selected[i] = false;
		ball.pop_back();
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int n;
		cin >> n >> check[i][0] >> check[i][1];

		for (int j = 2; j >= 0; j--)
		{
			num[i][j] = n % 10;
			n /= 10;
		}
	}

	DFS(0);
	cout << ans;
}