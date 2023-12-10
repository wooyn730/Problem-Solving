#include <iostream>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	string s;
	cin >> s;
	int nowStick = 0;
	int cuttedStick = 0;

	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == '(')
		{
			if (s[i + 1] == ')')
			{
				cuttedStick += nowStick;
				i++;
			}
			else
			{
				nowStick++;
			}
		}
		else
		{
			cuttedStick++;
			nowStick--;
		}
	}

	cout << cuttedStick;
}