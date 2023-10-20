#include <iostream>
#include <string>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int a1, b1, a2, b2, A, B;
	cin >> a1 >> b1 >> a2 >> b2;

	A = a1 * b2 + a2 * b1;
	B = b1 * b2;
	for (int i = 2; i <= (A > B ? B : A); i++)
	{
		while (A % i == 0 && B % i == 0)
		{
			A /= i;
			B /= i;
		}
	}

	cout << A << " " << B;
}