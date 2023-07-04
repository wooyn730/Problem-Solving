#include <iostream>
using namespace std;

int main()
{
	int N, ans = 1, honeyComb = 6;
	cin >> N;

	N -= 1;
	while (N > 0)
	{
		N -= honeyComb;
		honeyComb += 6;
		ans++;
	}
	
	cout << ans;
	return 0;
}