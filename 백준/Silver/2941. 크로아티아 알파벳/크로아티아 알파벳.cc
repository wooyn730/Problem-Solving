#include <iostream>
using namespace std;

int main()
{
	string S;
	cin >> S;
	int cnt = S.length();

	for (int i = 0; i < S.length(); i++)
	{
		switch (S[i]) // =로 끝나는 것, -로 끝나는 것, j로 끝나는 것
		{
		case '=':
			if (i - 1 >= 0)
				if (S[i - 1] == 'c' || S[i - 1] == 's' || S[i - 1] == 'z')
					cnt--;
			if (i - 2 >= 0 && S[i - 2] == 'd' && S[i - 1] == 'z')
				cnt--;
			break;
		case '-':
			if (i - 1 >= 0)
				if (S[i - 1] == 'c' || S[i - 1] == 'd')
					cnt--;
			break;
		case 'j':
			if (i - 1 >= 0)
				if (S[i - 1] == 'l' || S[i - 1] == 'n')
					cnt--;
			break;
		}
	}
	cout << cnt;
	return 0;
}