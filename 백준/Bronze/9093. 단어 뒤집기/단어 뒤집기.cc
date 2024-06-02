#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;
	cin.ignore();
	for (int i=0; i<T; i++)
	{
		string s;
		getline(cin, s);

		stack<char> stack;

		for (int i = 0; i < s.length(); i++)
		{
			if (s[i] == ' ')
			{
				while (!stack.empty())
				{
					cout << stack.top();
					stack.pop();
				}
				cout << ' ';
			}
			else
			{
				stack.push(s[i]);
			}
		}

		while (!stack.empty())
		{
			cout << stack.top();
			stack.pop();
		}
		cout << "\n";
	}
}