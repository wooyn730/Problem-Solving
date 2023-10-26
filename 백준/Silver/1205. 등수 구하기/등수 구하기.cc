#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, newScore, P, cnt=0;
	cin >> N >> newScore >> P;
	vector<int> vec;
	
	int T = (N > P ? P : N);
	while (T--)
	{
		int num;
		cin >> num;
		vec.push_back(num);

		if (num == newScore)
			cnt++;
	}
	vec.push_back(newScore);
	
	sort(vec.rbegin(), vec.rend());

	for (int i = 0; ; i++)
	{
		if (vec[i] == newScore)
		{
			if (i + 1 + cnt > P)
				cout << -1;
			else
				cout << i + 1;
			break;
		}
	}
}