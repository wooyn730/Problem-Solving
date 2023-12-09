#include <iostream>
using namespace std;

long long Fibo[91];

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	;
	int num;
	cin >> num;

	Fibo[1] = 1;
	Fibo[2] = 1;
	for (int i = 3; i <= num; i++)
	{
		Fibo[i] = Fibo[i - 1] + Fibo[i - 2];
	}

	cout << Fibo[num];

}