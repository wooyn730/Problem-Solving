#include <iostream>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	string ans = "";

	while (N--)
	{
		string s;
		cin >> s;

		if (ans == "")
			ans = s;
		else
		{
			for (int i = 0; i < s.length(); i++)
				if (ans[i] != '?' && ans[i] != s[i])
					ans[i] = '?';
		}
	}

	cout << ans;
}