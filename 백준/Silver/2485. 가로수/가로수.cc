#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	vector<int> v;
	set<int> s;

	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int tree;
		cin >> tree;
		v.push_back(tree);
	}

	for (int i = 0; i < v.size() - 1; i++)
	{
		s.insert(v[i + 1] - v[i]);
	}

	bool isSame;
	int div = *s.begin();
	set<int> ::iterator iter;

	while (true)
	{
		isSame = true;
		for (iter = s.begin(); iter != s.end(); iter++)
		{
			if (*iter % div != 0)
			{
				isSame = false;
				break;
			}
		}

		if (!isSame)
			div--;
		else
			break;
	}
	
	cout << (v[N - 1] - v[0]) / div - N + 1;
	return 0;
}