#include <iostream>
#include <string>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	int i = 1;
	while (n > i)
	{
		n -= i++;
	}

	if (i % 2 == 1)
		cout << i - n + 1 << "/" << n;
	else
		cout << n << "/" << i - n + 1;
}