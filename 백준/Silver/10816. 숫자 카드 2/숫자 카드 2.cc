#include <iostream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	map<int, int> cards;
	int N, M, num;
	cin >> N;

	while (N--)
	{
		cin >> num;

		if (cards.find(num) != cards.end())
			cards[num]++;
		else
			cards.insert({ num, 1 });
	}

	cin >> M;
	while (M--)
	{
		cin >> num;

		if (cards.find(num) != cards.end())
			cout << cards[num] << " ";
		else
			cout << "0 ";
	}

	return 0;
}