#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	string N;
	int B;
	cin >> N >> B;

	int sum = 0;
	for (int i = N.length() - 1; i >= 0; i--)
	{
		int num;
		if (N[i] >= 'A')
			num = N[i] - 'A' + 10;
		else
			num = N[i] - '0';

		sum += pow(B, (N.length() - 1 - i)) * num;
	}
	cout << sum;
	return 0;
}