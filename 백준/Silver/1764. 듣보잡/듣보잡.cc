#include <iostream>
#include <string>
#include <set>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	set<string> h;
	set<string> hs;
	int N, M;
	cin >> N >> M;

	while (N--)
	{
		string s;
		cin >> s;

		h.insert(s);
	}

	while (M--)
	{
		string s;
		cin >> s;

		auto i = h.find(s);
		if (i != h.end())
		{
			hs.insert(s);
		}
	}

	cout << hs.size() << "\n";

	for (set<string>::iterator iter = hs.begin(); iter != hs.end(); iter++)
	{
		cout << *iter << "\n";
	}
}