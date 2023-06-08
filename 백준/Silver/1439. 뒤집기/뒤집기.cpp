#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	string S;
	cin >> S;

	int ans = 0;
	bool toChange = false;
	char main = S[0];


	for (int i = 1; i < S.length(); i++)
	{
		if (!toChange)
		{
			if (S[i] != main)
			{
				toChange = true;
				S[i] = main;
				ans++;
			}
		}
		else
		{
			if (S[i] != main)
				S[i] = main;
			else
				toChange = false;
		}
	}
	
	cout << ans;
	return 0;
}