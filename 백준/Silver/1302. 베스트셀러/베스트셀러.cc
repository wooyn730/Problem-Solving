#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

bool compare(pair<string, int> a, pair<string, int> b)
{
	if (a.second == b.second)
		return a.first < b.first;
	else
		return a.second > b.second;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	map<string, int> book;
	string best;

	while (N--)
	{
		string title;
		cin >> title;
		if (book.empty())
			best = title;
		if (book.find(title) != book.end())
			book[title]++;
		else
			book.insert({ title, 1 });
	}

	for (auto iter = book.begin(); iter != book.end(); iter++)
	{
		if (book[best] < iter->second)
		{
			best = iter->first;
		}
		else if (book[best] == iter->second)
		{
			if (best > iter->first)
				best = iter->first;
		}
	}

	cout << best;
}