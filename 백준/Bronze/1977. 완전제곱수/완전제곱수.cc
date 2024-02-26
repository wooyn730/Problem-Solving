#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int M, N;
	cin >> M >> N;

	vector<int> vec;
	int m = sqrt(M), n = sqrt(N), sum = 0;
	if (m * m < M)
		m++;

	for (int i = m; i <= n; i++)
	{
		vec.push_back(i * i);
		sum += i * i;
	}
		
	if (vec.size() == 0)
		cout << -1;
	else
		cout << sum << "\n" << vec[0];

}