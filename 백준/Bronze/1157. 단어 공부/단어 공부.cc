#include <iostream>
using namespace std;

int main() 
{
	string S;
	cin >> S;
	int alphabet[26] = {0};
	int maxIdx = 0, maxCnt = 0;
	
	for (int i = 0; i < S.length(); i++)
	{
		S[i] = tolower(S[i]);
		alphabet[S[i] - 'a']++;
	}

	for (int i = 0; i < 26; i++)
		if (alphabet[i] > alphabet[maxIdx])
			maxIdx = i;

	for (int i = 0; i < 26; i++)
		if (alphabet[i] == alphabet[maxIdx])
			maxCnt++;

	if (maxCnt >= 2)
		cout << "?";
	else
		cout << (char)('A' + maxIdx);
	return 0;
}