#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	int N;
	cin >> N;
	int candidate[51];
	int buy = 0;
	bool haveToBuy = true;

	for (int i = 0; i < N; i++)
		cin >> candidate[i];
	
	sort(candidate + 1, candidate + N, greater<int>()); // 가장 많은 사람한테서 뺏기

	while (haveToBuy)
	{
		haveToBuy = false;

		if (candidate[1] < candidate[2])
			sort(candidate + 1, candidate + N, greater<int>());

		if (candidate[0] <= candidate[1])
		{
			candidate[0]++;
			candidate[1]--;
			buy++;
			haveToBuy = true;
		}
	}

	cout << buy;
	return 0;
}