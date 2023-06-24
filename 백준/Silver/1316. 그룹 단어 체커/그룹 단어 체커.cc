#include <iostream>
using namespace std;

int main()
{
	int N;
	cin >> N;
	int ans = 0;

	while (N--)
	{
		string S;
		cin >> S;
		bool alphabet[26] = { false };
		bool isGroupWord = true;

		for (int i = 0; i < S.length(); i++)
		{
			if (i >= 1 && S[i - 1] != S[i] && alphabet[S[i] - 'a'])
			{
				isGroupWord = false;
				break;
			}
			alphabet[S[i] - 'a'] = true;
		}
		ans += (isGroupWord ? 1 : 0);
	}
	
	cout << ans;
	return 0;
}