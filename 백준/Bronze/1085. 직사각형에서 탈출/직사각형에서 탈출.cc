#include <iostream>
using namespace std;

int main()
{
	int x, y, w, h, a, b;
	cin >> x >> y >> w >> h;

	a = min(x, y);
	b = min(w - x, h - y);
	cout << min(a, b);
	return 0;
}