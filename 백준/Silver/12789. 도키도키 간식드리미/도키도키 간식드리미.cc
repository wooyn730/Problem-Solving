#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	stack<int> s1;
	stack<int> s2;
	int order = 1;

	int T, T2, n;
	cin >> T;
	T2 = T;
	while (T--)
	{
		cin >> n;
		s2.push(n);
	}
	while (T2--)
	{
		s1.push(s2.top());
		s2.pop();
	}

	while (true)
	{
		if (!s1.empty() && s1.top() == order)
		{
			s1.pop();
			order++;
		}
		else if (!s2.empty() && s2.top() == order)
		{
			s2.pop();
			order++;
		}
		else if (!s1.empty())
		{
			s2.push(s1.top());
			s1.pop();
		}

		if (s1.empty() && s2.empty())
		{
			cout << "Nice";
			break;
		}

		if (s1.empty() && s2.top() != order)
		{
			cout << "Sad";
			break;
		}
	}
	return 0;
}