#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int N, sum=0;
	cin >> N;
	vector <int> A, B;
	int n;

	for (int i = 0; i < N; i++)
	{
		cin >> n;
		A.push_back(n);
	}

	for (int i = 0; i < N; i++)
	{
		cin >> n;
		B.push_back(n);
	}

	sort(A.begin(), A.end());
	sort(B.begin(), B.end());

	for (int i = 0; i < N; i++)
		sum += A[i] * B[N - 1 - i];

	cout << sum;
}