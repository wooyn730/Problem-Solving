#include <iostream>
#include <vector>
using namespace std;

int N, num[12], oper[4];
int _max = -1000000000, _min = 1000000000;
vector<int> vec;

void Calculate(int cnt)
{
	if (cnt == N - 1)
	{
		int sum = num[0];
		for (int i = 1; i < N; i++)
		{
			int tmp = 0;
			switch (vec[i - 1])
			{
			case 0:
				tmp = sum + num[i];
				break;
			case 1:
				tmp = sum - num[i];
				break;
			case 2:
				tmp = sum * num[i];
				break;
			case 3:
				tmp = sum / num[i];
				break;
			}
			sum = tmp;
		}
		
		_max = (sum > _max ? sum : _max);
		_min = (sum < _min ? sum : _min);
	}

	for (int i = 0; i < 4; i++)
	{
		if (oper[i] <= 0)
			continue;
		oper[i]--;
		vec.push_back(i);

		Calculate(cnt + 1);

		oper[i]++;
		vec.pop_back();
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> num[i];

	for (int i = 0; i < 4; i++)
		cin >> oper[i];

	Calculate(0);

	cout << _max << "\n" << _min;
}