#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int num[1000], N, k;
	cin >> N >> k;

	for (int i = 0; i < N; i++)
		cin >> num[i];

	sort(num, num + N);
	cout << num[N - k];
	return 0;
}