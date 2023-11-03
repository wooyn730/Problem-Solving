#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	
	string S, tmp = "";
	cin >> S;
	vector<string> suffix;
	
	for (int i = S.length() - 1; i >= 0; i--)
	{
		tmp = S[i] + tmp;
		suffix.push_back(tmp);
	}
	
	sort(suffix.begin(), suffix.end());

	for (int i = 0; i < suffix.size(); i++)
		cout << suffix[i] << "\n";
}