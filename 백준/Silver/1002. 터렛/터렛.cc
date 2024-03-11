#include <iostream>
#include <cmath>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;

	while (T--)
	{
		int x1, y1, r1, x2, y2, r2;
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

		double rSum = r1 + r2;
		double rDiff = (r1 - r2 > 0 ? r1 - r2 : r2 - r1);
		double distance = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));

		if (distance == 0 && r1 == r2)
			cout << "-1\n";
		else if (rSum < distance || rDiff > distance)
			cout << "0\n";
		else if (rSum == distance || rDiff == distance)
			cout << "1\n";
		else
			cout << "2\n";
	}
}