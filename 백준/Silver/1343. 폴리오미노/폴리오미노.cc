#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	string board;
	cin >> board;

	int start = 0;
	int end = 0;
	string tmp = "";

	
	if (board[0] == '.')
	{
		tmp += ".";
		start++;
	}
	else if (board.length() == 1)
	{
		cout << -1;
		return 0;
	}
	
	for (int i = 1; i < board.length(); i++)
	{
		if (board[i - 1] == '.' && board[i] == 'X')
		{
			start = i;
		}
		if ((board[i - 1] == 'X' && board[i] == '.') || (board[i] == 'X' && i == board.length() - 1))
		{
			end = (board[i] == 'X' && i == board.length() - 1) ? i + 1 : i;
			int len = end - start;

			if (len % 2 != 0)
			{
				cout << -1;
				return 0;
			}
			else
			{
				string t = "";
				while (len > 0)
				{
					if (len >= 4)
					{
						t += "AAAA";
						len -= 4;
					}
					else
					{
						t += "BB";
						len -= 2;
					}
				}
				tmp += t;
			}
		}

		if (board[i] == '.')
			tmp += ".";
	}
	cout << tmp;
	return 0;
}