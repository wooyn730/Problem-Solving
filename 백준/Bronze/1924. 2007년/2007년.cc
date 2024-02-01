#include <iostream>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int days[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	string day[7] = { "SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT" };
	
	int x, y;
	cin >> x >> y;

	for (int i = 0; i < x - 1; i++)
		y += days[i];

	cout << day[y % 7];
}