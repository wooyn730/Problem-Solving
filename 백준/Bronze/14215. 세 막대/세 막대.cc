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

	cin >> triangle[0] >> triangle[1] >> triangle[2];

	sort(triangle.rbegin(), triangle.rend());

	if (triangle[0] >= triangle[1] + triangle[2])
		triangle[0] = triangle[1] + triangle[2] - 1;

	cout << (triangle[0] + triangle[1] + triangle[2]);

}