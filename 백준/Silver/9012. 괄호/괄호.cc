#include <iostream>
#include <stack>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	string s;
	cin >> T;

	while (T--)
	{
		cin >> s;
		stack<int> stack;
		bool isStack = true;

		for (int i = 0; i < s.length(); i++)
		{
			if (s[i] == '(')
				stack.push(s[i]);
			else
			{
				if (!stack.empty())
					stack.pop();
				else
				{
					isStack = false;
					break;
				}
			}
		}
		if (!stack.empty())
			isStack = false;
		
		cout << (isStack ? "YES" : "NO") << "\n";
	}

	return 0;
}