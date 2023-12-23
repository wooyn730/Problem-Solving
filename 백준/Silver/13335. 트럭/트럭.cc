#include <iostream>
#include <queue>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, w, L;
	cin >> n >> w >> L;

	queue<int> trucks;
	int t;
	for (int i = 0; i < n; i++)
	{
		cin >> t;
		trucks.push(t);
	}

	queue<int> bridge;
	for (int i = 0; i < w; i++)
	{
		bridge.push(0);
	}

	int truckCnt = 0, truckWeight = 0, time = 0;
	while (!(trucks.empty() && truckCnt == 0))
	{
		if (bridge.front() != 0)
		{
			truckCnt--;
			truckWeight -= bridge.front();
		}
		bridge.pop();

		if (!trucks.empty() && truckCnt + 1 <= w && truckWeight + trucks.front() <= L)
		{
			truckCnt++;
			truckWeight += trucks.front();

			bridge.push(trucks.front());
			trucks.pop();
		}
		else
			bridge.push(0);

		time++;
	}
	cout << time;
}