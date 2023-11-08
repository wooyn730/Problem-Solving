#include <iostream>
#include <set>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	set<pair<int, int>> square;
	int x1, x2, y1, y2;

	for (int i = 0; i < 4; i++)
	{
		cin >> x1 >> y1 >> x2 >> y2;

		for (int x = x1; x < x2; x++)
		{
			for (int y = y1; y < y2; y++)
			{
				square.insert(make_pair(x, y));
			}
		}
	}

	cout << square.size();
}