#include <iostream>
#include <deque>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;
	deque<int> cards;

	for (int i = 1; i <= N; i++)
		cards.push_back(i);

	while (true)
	{
		if (cards.size() == 1)
		{
			cout << cards.front();
			break;
		}

		cout << cards.front() << " ";
		cards.pop_front();
		cards.push_back(cards.front());
		cards.pop_front();
	}
}