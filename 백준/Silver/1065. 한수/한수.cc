#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	
	int N;
	cin >> N;
	
	if (N < 100)
	{
		cout << N;
		return 0;
	}
	else
	{
		int hansu = 99;

		for (int i = 100; i <= N; i++)
		{
			int num = i;
			int a = num % 10;
			int b = num / 10 % 10;
			int c = num / 100;

			if (c - b == b - a)
				hansu++;

		}
		cout << hansu;
		return 0;
	}
}