#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	vector<pair<int, int>> scores(8);
	vector<int> q_num(5);

	for (int i = 0; i < 8; i++)
	{
		cin >> scores[i].first;
		scores[i].second = i + 1;
	}

	sort(scores.rbegin(), scores.rend());
	
	int sum = 0;
	for (int i = 0; i < 5; i++)
	{
		sum += scores[i].first;
		q_num[i] = scores[i].second;
	}
	cout << sum << "\n";

	sort(q_num.begin(), q_num.end());

	for (int i = 0; i < 5; i++)
	{
		cout << q_num[i] << " ";
	}
}