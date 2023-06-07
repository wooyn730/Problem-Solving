#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	long long S;
	cin >> S;
	int N = 0;

	for (int i = 1; ; i++)
	{
		if (S - i < 0)
			break;
		else
		{
			S -= i;
			N++;
		}
	}
	cout << N;
	return 0;
}