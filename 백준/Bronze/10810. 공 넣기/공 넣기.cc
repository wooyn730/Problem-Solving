#include <iostream>
using namespace std;

int main() {
	int N, M;
	cin >> N >> M;
	int basket[101] = { 0 };

	while (M--)
	{
		int i=0, j=0, k=0;
		cin >> i >> j >> k;

		for (int n = i; n <= j; n++)
			basket[n] = k;
	}

	for (int i = 1; i <= N; i++)
		cout << basket[i] << " ";
	return 0;
}