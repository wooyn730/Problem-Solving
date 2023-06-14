#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int dwarf[9] ={ 0 };
	int sum = -100, nd1, nd2;
	
	for (int i = 0; i < 9; i++)
	{
		cin >> dwarf[i];
		sum += dwarf[i];
	}
	
	sort(dwarf, dwarf + 9);

	for (int i = 0; i < 9; i++)
	{
		for (int j = i + 1; j < 9; j++)
		{
			if (dwarf[i] + dwarf[j] == sum)
			{
				nd1 = i;
				nd2 = j;
			}
		}
	}

	for (int i = 0; i < 9; i++)
	{
		if (i != nd1 && i != nd2)
			cout << dwarf[i] << '\n';
	}
}