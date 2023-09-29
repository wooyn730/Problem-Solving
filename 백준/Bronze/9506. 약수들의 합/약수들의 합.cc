#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	vector<int> perfect;

	while (true)
	{
		perfect.clear();
		int num, sum = 0;
		cin >> num;

		if (num == -1)
			break;

		for (int i = 1; i < num; i++)
		{
			if (num % i == 0)
			{
				perfect.push_back(i);
				sum += i;
			}
		}

		if (sum == num)
		{
			cout << num << " = ";
			for (int i = 0; i < perfect.size(); i++)
			{
				cout << perfect[i];
				if (i != perfect.size() - 1)
					cout << " + ";
				else
					cout << "\n";
			}
		}
		else
			cout << num << " is NOT perfect.\n";
	}

	return 0;
}