#include <iostream>
#include <string>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	long long n;
	cin >> n;
	cout << (n % 2 == 0 ? n - 1 : n) * (n / 2) << "\n" << 2;
}