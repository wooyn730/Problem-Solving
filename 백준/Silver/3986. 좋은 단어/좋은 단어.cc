#include <iostream>
#include <stack>
using namespace std;

bool CheckGoodWord(string s)
{
	stack<char> ab;
	char out = NULL, in;

	for (int i = 0; i < s.length(); i++)
	{
		if (!ab.empty() && ab.top() == s[i])
			ab.pop();
		else
			ab.push(s[i]);
	}

	while (!ab.empty())
	{
		if (out == NULL)
		{
			out = ab.top();
		}
		else
		{
			in = ab.top();

			if (in != out)
				return false;
			else
				out = NULL;
		}
		ab.pop();
	}

	return out == NULL;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, cnt = 0;
	cin >> N;
	string s;

	while (N--)
	{
		cin >> s;
		cnt += (CheckGoodWord(s) ? 1 : 0);
	}

	cout << cnt;
}