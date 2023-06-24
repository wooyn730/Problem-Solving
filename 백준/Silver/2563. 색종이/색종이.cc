#include <iostream>
using namespace std;

int main()
{
	int N, paper[100][100] = {0}, sum = 0;
	cin >> N;

	while (N--)
	{
		int a, b;
		cin >> a >> b;
		
		for (int i = a; i < a + 10; i++)
		{
			for (int j = b; j < b + 10; j++)
			{
				if (!paper[i][j])
				{
					paper[i][j] = 1;
					sum++;
				}
			}
		}
	}

	cout << sum;
	return 0;
}