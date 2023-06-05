#include <iostream>
#include <vector>
using namespace std;

int main() {
	int N, K; // N: 동전 개수, K: 목표 금액
	cin >> N >> K;
	vector<int> A(N); // 동전 가치

	int sum = 0;
	int cnt = 0;

	for (int i = 0; i < N; i++)
		cin >> A[i];

	for (int i = N - 1; i >= 0; i--)
	{
		if (sum + A[i] <= K)
		{
			int tmp = (K - sum) / A[i];
			sum += A[i] * tmp;
			cnt += tmp;
		}
		
		if (sum == K)
		{
			cout << cnt;
			return 0;
		}
	}
}