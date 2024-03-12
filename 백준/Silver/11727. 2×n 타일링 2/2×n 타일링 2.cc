#include <iostream>
using namespace std;

int method[1001];

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	method[1] = 1;
	method[2] = 3;

	for (int i = 3; i <= n; i++)
		method[i] = (method[i - 1] + method[i - 2] * 2) % 10007;

	cout << method[n];
}