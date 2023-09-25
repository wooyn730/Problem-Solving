#include <iostream>
#include <string>
#include <set>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	set<string> set;

	string S;
	cin >> S;

	for (int i = 0; i < S.length(); i++)
	{
		for (int j = 0; j < S.length(); j++)
		{
			string str = S.substr(i, j);
			set.insert(str);
		}
	}

	cout << set.size();
	return 0;
}