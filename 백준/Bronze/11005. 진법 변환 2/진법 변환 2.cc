#include <iostream>
using namespace std;

int main()
{
	int N, B;
	cin >> N >> B;
	string ans = "";

	while (N)
	{
		int k = N % B;
		if (k >= 10)
			k += 'A' - 10;
		else
			k += '0';

		ans = char(k) + ans;
		N /= B;
	}
	cout << ans;
	return 0;
}