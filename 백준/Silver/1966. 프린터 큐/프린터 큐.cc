#include <iostream>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;

	while (T--)
	{
		queue<pair<int, bool>> printer;
		map<int, int, greater<int>> file;
		int N, M, num, cnt = 0;
		cin >> N >> M;

		for (int i = 0; i < N; i++)
		{
			cin >> num;

			if (i != M)
				printer.push(make_pair(num, false));
			else
				printer.push(make_pair(num, true));

			if (file.find(num) != file.end())
				file[num]++;
			else
				file.insert({ num, 1 });
		}

		bool isFind = false;
		for (auto iter = file.begin(); iter != file.end(); iter++)
		{
			while (iter->second > 0)
			{
				if (printer.front().first == iter->first)
				{
					cnt++;
					iter->second = iter->second - 1;
					if (printer.front().second)
					{
						isFind = true;
						break;
					}
				}
				else
				{
					printer.push(printer.front());
				}
				printer.pop();
			}

			if (isFind)
				break;
		}
		cout << cnt << "\n";
	}
}