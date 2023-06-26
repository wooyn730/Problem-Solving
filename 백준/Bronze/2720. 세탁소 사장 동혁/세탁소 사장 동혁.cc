#include <iostream>
using namespace std;

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		const double Quater = 25, Dime = 10, Nickel = 5, Penny = 1;
		double C, Q = 0, D = 0, N = 0, P = 0;
		cin >> C;

		while (C >= Quater)
		{
			C -= Quater;
			Q++;
		}
		while (C >= Dime)
		{
			C -= Dime;
			D++;
		}
		while (C >= Nickel)
		{
			C -= Nickel;
			N++;
		}
		while (C >= Penny)
		{
			C -= Penny;
			P++;
		}

		cout << Q << " " << D << " " << N << " " << P << endl;
	}
	return 0;
}