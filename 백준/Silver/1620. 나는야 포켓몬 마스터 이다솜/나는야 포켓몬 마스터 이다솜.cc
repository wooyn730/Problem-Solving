#include <iostream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	map<string, int> poketmon; // key, value
	map<int, string> poketmon2;
	int N, M, val=1;
	cin >> N >> M;

	while (N--)
	{
		string name;
		cin >> name;

		poketmon[name] = val;
		poketmon2[val++] = name;
	}

	while (M--)
	{
		string input;
		cin >> input;

		if (input[0] - '0' >= 0 && input[0] - '0' <= 9)
		{
			cout << poketmon2[stoi(input)] << "\n";
		}
		else
			cout << poketmon[input] << "\n";
	}

	return 0;
}