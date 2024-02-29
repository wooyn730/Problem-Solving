#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int L, C;
vector<char> alphabet;
vector<char> word;
bool selected[26];

void GetPassword(int idx)
{
	if (word.size() == L)
	{
		int vowel = 0;
		int consonant = 0;
		string ans = "";
		for (int i = 0; i < L; i++)
		{
			if (word[i] == 'a' || word[i] == 'e' || word[i] == 'i' || word[i] == 'o' || word[i] == 'u')
				vowel++;
			else
				consonant++;
			ans += word[i];
		}
		
		if (vowel >= 1 && consonant >= 2)
			cout << ans << "\n";
		return;
	}

	for (int i = idx; i < alphabet.size(); i++)
	{
		int num = alphabet[i] - 'a';
		if (selected[num])
			continue;
		selected[num] = true;
		word.push_back(alphabet[i]);
		GetPassword(i);
		selected[num] = false;
		word.pop_back();
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> L >> C;

	for (int i = 0; i < C; i++)
	{
		char c;
		cin >> c;
		alphabet.push_back(c);
	}

	sort(alphabet.begin(), alphabet.end());

	GetPassword(0);
}