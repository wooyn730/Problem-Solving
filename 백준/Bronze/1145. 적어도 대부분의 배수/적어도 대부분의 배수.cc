#include <iostream>
using namespace std;

int main() {
	int nums[5];

	for (int i = 0; i < 5; i++)
		cin >> nums[i];

	for (int i = 1; ; i++)
	{
		int check = 0;
		for (int n : nums)
		{
			if (i % n == 0)
				check++;
		}
		if (check >= 3)
		{
			cout << i;
			return 0;
		}
	}
}