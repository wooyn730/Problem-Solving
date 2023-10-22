#include <iostream>
#include <string>
using namespace std;

int numbers[46];

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int K;
	cin >> K;

	numbers[1] = 0;
	numbers[2] = 1;

	for (int i = 3; i <= K + 1; i++)
	{
		numbers[i] = numbers[i - 1] + numbers[i - 2];
	}
	cout << numbers[K] << " " << numbers[K+1];
}