#include <iostream>
#include <string>
#include <cmath>
using namespace std;

bool isPalindrome(int n)
{
	string s = to_string(n);

	for (int i = 0; i < s.length() / 2; i++)
	{
		if (s[i] != s[s.length() - 1 - i])
			return false;
	}

	return true;
}

bool isPrime(int n)
{
	if (n == 1)
		return false;

	for (int i = 2; i <= sqrt(n); i++)
	{
		if (n % i == 0)
			return false;
	}

	return true;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	for (int i = N; ; i++)
	{
		if (isPalindrome(i) && isPrime(i))
		{
			cout << i;
			break;
		}
	}
}