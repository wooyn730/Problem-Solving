#include <iostream>
#include <cmath>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	long long n, q;
	cin >> n;
	
	q = sqrt(n);

	if (q * q < n)
		q += 1;

	cout << q;
}