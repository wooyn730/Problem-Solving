#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string fibo[10001];

string Sum(string s1, string s2)
{
	string answer_string = "";

	reverse(s1.begin(), s1.end());
	reverse(s2.begin(), s2.end());

	int bigNum = (s1.length() > s2.length() ? s1.length() : s2.length());
	int carry = 0;
	for (int i = 0; i <= bigNum; i++)
	{
		int number = carry;

		if (i < s1.size())
			number += s1[i] - '0';

		if (i < s2.size())
			number += s2[i] - '0';

		if (number >= 10)
		{
			carry = 1;
			number -= 10;
		}
		else
			carry = 0;

		if (i == bigNum && number == 0)
			continue;
		answer_string += to_string(number);
	}

	reverse(answer_string.begin(), answer_string.end());
	return answer_string;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	fibo[0] = "0";
	fibo[1] = "1";

	for (int i = 2; i <= N; i++)
		fibo[i] = Sum(fibo[i - 1], fibo[i - 2]);
	
	cout << fibo[N];
}