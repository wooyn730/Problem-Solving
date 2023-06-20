#include <iostream>
using namespace std;

int main() {
	int X, N, sum=0;
	cin >> X >> N;

	while (N--)
	{
		int a, b;
		cin >> a >> b;
		sum += a * b;
	}

	cout << (X == sum ? "Yes" : "No");
	return 0;
}