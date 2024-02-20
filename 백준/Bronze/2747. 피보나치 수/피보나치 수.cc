#include <iostream>
using namespace std;

int Fibo[46];

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	Fibo[0] = 0;
	Fibo[1] = 1;

	for (int i = 2; i < n + 1; i++)
	{
		Fibo[i] = Fibo[i - 1] + Fibo[i - 2];
	}

	cout << Fibo[n];
}