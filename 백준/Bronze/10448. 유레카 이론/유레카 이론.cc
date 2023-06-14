#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	
	int T, K;
	cin >> T;
	const int size = 46;
	int samgaksu[size]; // 45*46 = 2070
	
	for (int i = 1; i < size; i++)
		samgaksu[i] = i * (i + 1) / 2;

	while (T--)
	{
		cin >> K;
		bool possible = false;
		for (int i = 1; i < size; i++)
		{
			for (int j = 1; j < size; j++)
			{
				for (int k = 1; k < size; k++)
				{
					if (samgaksu[i] + samgaksu[j] + samgaksu[k] == K)
					{
						possible = true;
						break;
					}
						
				}
			}
		}
		cout << (possible ? 1 : 0) << endl;
	}

		
	return 0;
}