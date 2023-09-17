#include <iostream>
#include <string>
#include <deque>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	deque<int> deque;
	int N;
	cin >> N;

	while (N--)
	{
		int command, num;
		cin >> command;

		switch (command)
		{
		case 1:
			cin >> num;
			deque.push_front(num);
			break;
		case 2:
			cin >> num;
			deque.push_back(num);
			break;
		case 3:
			if (deque.empty())
				cout << "-1" << "\n";
			else
			{
				cout << deque.front() << "\n";
				deque.pop_front();
			}
			break;
		case 4:
			if (deque.empty())
				cout << "-1" << "\n";
			else
			{
				cout << deque.back() << "\n";
				deque.pop_back();
			}
			break;
		case 5:
			cout << deque.size() << "\n";
			break;
		case 6:
			if (deque.empty())
				cout << "1" << "\n";
			else
				cout << "0" << "\n";
			break;
		case 7:
			if (deque.empty())
				cout << "-1" << "\n";
			else
				cout << deque.front() << "\n";
			break;
		case 8:
			if (deque.empty())
				cout << "-1" << "\n";
			else
				cout << deque.back() << "\n";
			break;
		}
	}
	return 0;
}