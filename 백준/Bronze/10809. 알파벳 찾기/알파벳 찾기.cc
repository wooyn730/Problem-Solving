#include <iostream>
using namespace std;

int main() {
	int alphabet[26];
	for (int i = 0; i < 26; i++)
		alphabet[i] = -1;

	string S;
	cin >> S;
	for (int i = 0; i < S.length(); i++)
	{
		for (int j = 0; j < S.length(); j++)
		{
			if (S[i] == S[j])
			{
				alphabet[S[i] - 'a'] = j;
				break;
			}
		}
	}

	for (int a : alphabet)
		cout << a << " ";
	return 0;
}