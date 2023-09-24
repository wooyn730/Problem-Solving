#include <iostream>
#include <string>
#include <map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	map<int, bool> A;
	map<int, bool> B;

	int Anum, Bnum, n, ans = 0;
	cin >> Anum >> Bnum;

	while (Anum--)
	{
		cin >> n;
		A.insert({ n, true });
	}

	while (Bnum--)
	{
		cin >> n;
		B.insert({ n, true });
	}

	map<int, bool> ::iterator iter;
	for (iter = A.begin(); iter != A.end(); iter++)
	{
		if (A.find(iter->first) != A.end() && B.find(iter->first) == B.end())
			ans++;
	}
	for (iter = B.begin(); iter != B.end(); iter++)
	{
		if (B.find(iter->first) != B.end() && A.find(iter->first) == A.end())
			ans++;
	}

	cout << ans;
	return 0;
}