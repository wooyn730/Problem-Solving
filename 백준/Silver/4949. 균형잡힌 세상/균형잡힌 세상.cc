#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	while (true)
	{
		stack<int> stack;
		string s;
		getline(cin, s);

		if (s == ".")
			break;

		bool isStack = true;

		for (int i = 0; i < s.length(); i++)
		{
			if (s[i] == '(' || s[i] == '[')
				stack.push(s[i]);
			else if (s[i] == ')' || s[i] == ']')
			{
				if (stack.empty())
				{
					isStack = false;
					break;
				}
				else
				{
					if (s[i] == ')' && stack.top() == '(')
						stack.pop();
					else if (s[i] == ']' && stack.top() == '[')
						stack.pop();
					else
					{
						isStack = false;
						break;
					}
				}
			}
		}

		if (!stack.empty())
			isStack = false;
		
		cout << (isStack ? "yes" : "no") << "\n";
	}

	return 0;
}