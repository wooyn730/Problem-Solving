#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int N, min_x, min_y, max_x, max_y;
	cin >> N;
	for (int i=0; i<N; i++)
	{
		int x, y;
		cin >> x >> y;
		if (i == 0)
		{
			min_x = x;
			max_x = x;
			min_y = y;
			max_y = y;
		}
		else
		{
			if (min_x > x)
				min_x = x;
			if (max_x < x)
				max_x = x;
			if (min_y > y)
				min_y = y;
			if (max_y < y)
				max_y = y;
		}
	}

	cout << (max_x - min_x) * (max_y - min_y);
	return 0;
}