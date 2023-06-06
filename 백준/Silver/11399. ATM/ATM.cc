#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int N;
	cin >> N;
	int p[1000], sum=0;

	for (int i=0; i<N; i++)
		cin >> p[i];

	sort(p, p + N);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j <= i; j++)
			sum += p[j];
	}
	cout << sum;
}