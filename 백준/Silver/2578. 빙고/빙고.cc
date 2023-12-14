#include <iostream>
using namespace std;

int bingo[5][5];

int CheckLines()
{
	int line = 0;

	// 가로, 세로 선 긋기
	for (int i = 0; i < 5; i++)
	{
		bool isBingoA = true, isBingoB = true;
		for (int j = 0; j < 5; j++)
		{
			if (bingo[i][j] != 0)
				isBingoA = false;
			if (bingo[j][i] != 0)
				isBingoB = false;
		}
		if (isBingoA)
			line++;
		if (isBingoB)
			line++;
	}

	// 대각선 선 긋기
	bool isBingoC = true, isBingoD = true;
	for (int i = 0; i < 5; i++)
	{
		if (bingo[i][i] != 0)
			isBingoC = false;
		if (bingo[4 - i][i] != 0)
			isBingoD = false;
	}
	if (isBingoC)
		line++;
	if (isBingoD)
		line++;

	return line;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int ans = 0;

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cin >> bingo[i][j];
		}
	}
	
	while (true)
	{
		int num;
		cin >> num;
		ans++;

		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				if (bingo[i][j] == num)
					bingo[i][j] = 0;
			}
		}

		if (ans >= 12)
		{
			if (CheckLines() >= 3)
			{
				cout << ans;
				break;
			}
		}
	}
}