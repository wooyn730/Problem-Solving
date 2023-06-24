#include <iostream>
using namespace std;

int main()
{
	int A[9][9], max = 0, maxi = 0, maxj = 0;
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cin >> A[i][j];
			if (A[i][j] > max)
			{
				max = A[i][j];
				maxi = i;
				maxj = j;
			}
		}
	}

	cout << max << endl << maxi+1 << " " << maxj+1;
	return 0;
}