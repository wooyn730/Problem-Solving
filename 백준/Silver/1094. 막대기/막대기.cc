#include <iostream>
#include <stack>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	stack<int> stick;
	stick.push(64);
	int sum = 64, cnt = 0, X;
	cin >> X;
	
	while (true)
	{
		if (sum > X)
		{
			stick.top() /= 2;
			if (sum - stick.top() < X)
				stick.push(stick.top());
			else
				sum -= stick.top();
		}
		else if (sum == X)
			break;
	}

	while (!stick.empty())
	{
		stick.pop();
		cnt++;
	}

	cout << cnt;
}