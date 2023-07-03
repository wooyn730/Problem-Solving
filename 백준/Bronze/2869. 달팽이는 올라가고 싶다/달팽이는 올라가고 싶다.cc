#include <iostream>
using namespace std;

int main()
{
	int A, B, V, ans = 1;
	cin >> A >> B >> V;

	V -= A;
	ans += V / (A - B) + (V % (A - B) == 0 ? 0 : 1);

	cout << ans;
	return 0;
}