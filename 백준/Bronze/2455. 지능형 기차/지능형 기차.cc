#include <iostream>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int out, in, cnt = 0, max = 0;

	for (int i = 0; i < 4; i++)
	{
		cin >> out >> in;

		cnt += in - out;
		max = cnt > max ? cnt : max;
	}

	cout << max;
}