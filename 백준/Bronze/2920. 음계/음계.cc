#include <iostream>
using namespace std;

int scale[8];

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	for (int i = 0; i < 8; i++)
		cin >> scale[i];
	
	if (scale[0] == 1 && scale[1] == 2 && scale[2] == 3 && scale[3] == 4 &&
		scale[4] == 5 && scale[5] == 6 && scale[6] == 7 && scale[7] == 8)
		cout << "ascending";
	else if (scale[0] == 8 && scale[1] == 7 && scale[2] == 6 && scale[3] == 5 &&
		scale[4] == 4 && scale[5] == 3 && scale[6] == 2 && scale[7] == 1)
		cout << "descending";
	else
		cout << "mixed";
}