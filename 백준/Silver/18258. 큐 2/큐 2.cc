#include <iostream>
#include <string>
#include <queue>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	queue<int> queue;
	int N;
	cin >> N;

	while (N--)
	{
		string str;
		cin >> str;

		if (str[0] == 'p' && str[1] == 'u')
		{
			int X;
			cin >> X;
			queue.push(X);
		}
		else
		{
			if (str[0] == 'p' && str[1] == 'o')
			{
				if (queue.empty())
					cout << "-1";
				else
				{
					cout << queue.front();
					queue.pop();
				}
			}
			else if (str[0] == 's')
			{
				cout << queue.size();
			}
			else if (str[0] == 'e')
			{
				cout << (queue.empty() ? 1 : 0);
			}
			else if (str[0] == 'f')
			{
				if (queue.empty())
					cout << "-1";
				else
				{
					cout << queue.front();
				}
			}
			else if (str[0] == 'b')
			{
				if (queue.empty())
					cout << "-1";
				else
				{
					cout << queue.back();
				}
			}
			cout << "\n";
		}
	}

	return 0;
}