#include <iostream>
#include <map>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int T;
	cin >> T;

	while (T--)
	{
		int n, ans = 1;
		cin >> n;

		if (n != 0)
		{
			map<string, int> fassion;

			for (int i = 0; i < n; i++)
			{
				string name, type;
				cin >> name >> type;
				if (fassion.find(type) != fassion.end())
					fassion[type]++;
				else
					fassion.insert({ type, 1 });
			}

			for (auto iter : fassion)
				ans *= (iter.second + 1);
		}

		cout << ans - 1 << "\n";
	}
}