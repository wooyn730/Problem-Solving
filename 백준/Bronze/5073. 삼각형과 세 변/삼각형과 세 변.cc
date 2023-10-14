#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	vector<int> triangle(3);

	while (true)
	{
		cin >> triangle[0] >> triangle[1] >> triangle[2];
		if (triangle[0] == 0 && triangle[1] == 0 && triangle[2] == 0)
			break;

		sort(triangle.rbegin(), triangle.rend());

		if (triangle[0] >= triangle[1] + triangle[2])
			cout << "Invalid\n";
		else if (triangle[0] == triangle[1] && triangle[1] == triangle[2])
			cout << "Equilateral\n";
		else if (triangle[0] == triangle[1] || triangle[1] == triangle[2])
			cout << "Isosceles\n";
		else
			cout << "Scalene\n";
	}
}