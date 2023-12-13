#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

struct compare {
	bool operator()(pair<int, int>& a, pair<int, int>& b)
	{
		if (a.first == b.first)
			return a.second > b.second;
		return a.first > b.first;
	}
};

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;

	int N, x;
	cin >> N;

	while (N--)
	{
		cin >> x;
		if (x == 0)
		{
			if (pq.empty())
				cout << "0\n";
			else
			{
				cout << pq.top().second << "\n";
				pq.pop();
			}
		}
		else
		{
			pq.push(make_pair(abs(x), x));
		}
	}
}