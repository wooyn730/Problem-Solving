#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T, A, B;
	cin >> T;
	while (T--)
	{
		cin >> A >> B;
		if (A < B) // A가 크게
		{
			int tmp = A;
			A = B;
			B = tmp;
		}
		for (int i = 1; ; i++)
		{
			if (A * i % B == 0)
			{
				cout << A * i << "\n";
				break;
			}
		}
	}
	return 0;
}