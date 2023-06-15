#include <iostream>
#include <cmath>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	
	long long n;
	cin >> n;

	long long ans = sqrt(n);

	if (ans * ans < n)
		ans++;
	cout << ans;
	return 0;
}