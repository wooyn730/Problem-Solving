#include <iostream>
using namespace std;

int main()
{
	int N, M, A[100][100], B[100][100], C[100][100];
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> A[i][j];
			C[i][j] = A[i][j];
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> B[i][j];
			C[i][j] += B[i][j];
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cout << C[i][j] << " ";
		}
		if (i != N-1)
			cout << endl;
	}
	return 0;
}