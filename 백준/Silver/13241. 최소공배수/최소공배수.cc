#include <iostream>
using namespace std;

long long Euclidean(long long a, long long b)
{
	if (b == 0)
		return a;

	return Euclidean(b, a % b);
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	long long A, B;
	cin >> A >> B;

	cout << A * B / (A > B ? Euclidean(A, B) : Euclidean(B, A));
}