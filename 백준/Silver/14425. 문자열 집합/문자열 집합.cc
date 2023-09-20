#include <iostream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	map<string, bool> S;
	int N, M, cnt = 0;
	cin >> N >> M;

	while (N--)
	{
		string str;
		cin >> str;

		S[str] = true;
	}

	while (M--)
	{
		string input;
		cin >> input;

		if (S[input])
			cnt++;
	}
	
	cout << cnt;

	return 0;
}