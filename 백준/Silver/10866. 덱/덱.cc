#include <iostream>
#include <deque>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	deque<int> deq;
	int T, X;
	string command;

	cin >> T;

	while (T--)
	{
		cin >> command;
		if (command == "push_front")
		{
			cin >> X;
			deq.push_front(X);
		}
		else if (command == "push_back")
		{
			cin >> X;
			deq.push_back(X);
		}
		else
		{
			if (command == "pop_front")
			{
				if (!deq.empty())
				{
					cout << deq.front();
					deq.pop_front();
				}
				else
					cout << -1;
			}
			else if (command == "pop_back")
			{
				if (!deq.empty())
				{
					cout << deq.back();
					deq.pop_back();
				}
				else
					cout << -1;
			}
			else if (command == "size")
			{
				cout << deq.size();
			}
			else if (command == "empty")
			{
				cout << (deq.empty() ? 1 : 0);
			}
			else if (command == "front")
			{
				if (!deq.empty())
				{
					cout << deq.front();
				}
				else
					cout << -1;
			}
			else if (command == "back")
			{
				if (!deq.empty())
				{
					cout << deq.back();
				}
				else
					cout << -1;
			}

			cout << "\n";
		}
	}
}