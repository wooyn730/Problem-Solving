#include <iostream>
#include <string>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int a1, a0, c, n0;
	cin >> a1 >> a0 >> c >> n0;
	
	if (a1 * n0 + a0 <= c * n0 && a1 <= c)
		cout << 1;
	else
		cout << 0;
}