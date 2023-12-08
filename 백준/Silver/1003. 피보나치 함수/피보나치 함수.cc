#include <iostream>
using namespace std;

int Fibo[41];

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
;
	int T, num;
	cin >> T;

	while (T--)
	{
		cin >> num;
		
		if (num == 0)
			cout << "1 0\n";
		else if (num == 1)
			cout << "0 1\n";
		else
		{
			Fibo[0] = 0;
			Fibo[1] = 1;
			for (int i = 2; i <= num; i++)
			{
				Fibo[i] = Fibo[i - 1] + Fibo[i - 2];
			}

			cout << Fibo[num - 1] << " " << Fibo[num] << "\n";
		}
	}
}