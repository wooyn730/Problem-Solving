#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int A[101][101];
int B[101][101];
int C[101][101];

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M, K;
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> A[i][j];
		}
	}

	cin >> M >> K;
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < K; j++)
		{
			cin >> B[i][j];
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < K; j++)
		{
			for (int k = 0; k < M; k++)
			{
				C[i][j] += A[i][k] * B[k][j];
				
			}
			cout << C[i][j] << " ";
		}
		cout << "\n";
	}
}