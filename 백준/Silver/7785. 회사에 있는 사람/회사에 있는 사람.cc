#include <iostream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	map<string, bool, greater<>> company;
	int n;
	cin >> n;

	while (n--)
	{
		string name, type;
		cin >> name >> type;

		company[name] = (type == "enter" ? true : false);
	}

	map<string, bool> ::iterator iter;
	for (iter = company.begin(); iter != company.end(); iter++)
	{
		if (iter->second)
			cout << iter->first << "\n";
	}
	
	return 0;
}