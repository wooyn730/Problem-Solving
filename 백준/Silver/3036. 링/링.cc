#include <iostream>
using namespace std;

int gcd(int a, int b)
{
	return b ? (gcd(b, a % b)) : a;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	int ring;
	cin >> ring;

	for (int i = 0; i < N - 1; i++)
	{
		int another;
		cin >> another;
		int num = gcd(ring, another);
		cout << ring / num << "/" << another / num << "\n";
	}
}