#include <iostream>
using namespace std;

int main() 
{
	string S;
	cin >> S;
	bool isPalindrome = true;

	for (int i = 0; i < S.length() / 2; i++)
	{
		if (S[i] != S[S.length() - i - 1])
		{
			isPalindrome = false;
			break;
		}
	}
	cout << (isPalindrome ? 1 : 0);
	return 0;
}