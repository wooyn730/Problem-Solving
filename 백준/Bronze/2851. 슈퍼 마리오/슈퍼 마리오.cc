#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	
	int sum = 0;
	int mushroom[10];

	for (int i = 0; i < 10; i++)
		cin >> mushroom[i];

	for (int i = 0; i < 10; i++)
	{
		if (sum + mushroom[i] > 100)
		{
			if (sum + mushroom[i] - 100 <= 100 - sum)
			{
				sum += mushroom[i];
				break;
			}
			else
				break;
		}
		sum += mushroom[i];
	}

	cout << sum;
	return 0;
}