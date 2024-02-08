#include <iostream>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string s;
	cin >> s;

	int cnt = 1;
	for (int i = 0; i < s.length(); i++)
	{
		cout << s[i];
		
		if (cnt++ == 10)
		{
			cout << "\n";
			cnt = 1;
		}
	}
}