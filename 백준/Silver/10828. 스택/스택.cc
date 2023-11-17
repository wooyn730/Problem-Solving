#include <iostream>
#include <stack>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	stack<int> stack;
	int N;
	cin >> N;

	while (N--)
	{
		string command;
		cin >> command;

		if (command == "push")
		{
			int num;
			cin >> num;
			stack.push(num);
		}
		else if (command == "pop")
		{
			if (stack.empty())
				cout << -1 << "\n";
			else
			{
				cout << stack.top() << "\n";
				stack.pop();
			}
		}
		else if (command == "size")
		{
			cout << stack.size() << "\n";
		}
		else if (command == "empty")
		{
			cout << stack.empty() << "\n";
		}
		else if (command == "top")
		{
			if (stack.empty())
				cout << -1 << "\n";
			else
				cout << stack.top() << "\n";
		}
	}
}