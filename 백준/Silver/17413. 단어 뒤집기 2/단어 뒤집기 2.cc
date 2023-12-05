#include <iostream>
#include <string>
#include <stack>
using namespace std;

stack<char> rev;
bool isSign = false;
string ans;

void ReverseWord()
{
	while (!rev.empty())
	{
		ans += rev.top();
		rev.pop();
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string S;
	getline(cin, S);

	for (int i = 0; i < S.length(); i++)
	{
		if (S[i] == '<')
		{
			isSign = true;
			ReverseWord();
		}

		if (isSign)
			ans += S[i];
		else
		{
			if (S[i] == ' ')
			{
				ReverseWord();
				ans += ' ';
			}
			else
				rev.push(S[i]);
		}

		if (S[i] == '>')
			isSign = false;
	}

	ReverseWord();

	cout << ans;
}