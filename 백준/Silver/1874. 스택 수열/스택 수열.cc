#include <iostream>
#include <stack>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	stack<int> stack;
	int n, out, num = 0;
	bool possible = true;
	string ans = "";
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> out;
		if (!possible)
			continue;

		if (out > num)
		{
			while (num != out)
			{
				stack.push(++num);
				ans += '+';
			}
		}
		
		if (out == stack.top())
		{
			stack.pop();
			ans += '-';
		}
		else
		{
			possible = false;
		}
	}

	if (!possible)
		cout << "NO";
	else
		for (int i = 0; i < ans.length(); i++)
			cout << ans[i] << "\n";
}