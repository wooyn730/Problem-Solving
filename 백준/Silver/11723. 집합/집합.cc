#include <iostream>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	bool num[20] = { false };
	int T, x;
	cin >> T;
	string str;

	while (T--)
	{
		cin >> str;

		if (str == "add")
		{
			cin >> x;
			num[x - 1] = true;
		}
		else if (str == "remove")
		{
			cin >> x;
			num[x - 1] = false;
		}
		else if (str == "check")
		{
			cin >> x;
			cout << num[x - 1] << "\n";
		}
		else if (str == "toggle")
		{
			cin >> x;
			num[x - 1] = !num[x - 1];
		}
		else if (str == "all")
		{
			for (int i = 0; i < 20; i++)
				num[i] = true;
		}
		else if (str == "empty")
		{
			for (int i = 0; i < 20; i++)
				num[i] = false;
		}
	}
}