#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

static bool compare(pair<long long, int> &a, pair<long long, int> &b)
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

	map<long long, int> card;
	long long num;

	while (N--)
	{
		cin >> num;

		if (card.find(num) == card.end())
		{
			card.insert({ num, 1 });
		}
		else
			card[num]++;
	}

	vector<pair<long long, int>>vec(card.begin(), card.end());
	sort(vec.begin(), vec.end(), compare);

	cout << vec[0].first;
}