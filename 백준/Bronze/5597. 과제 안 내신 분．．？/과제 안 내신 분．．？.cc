#include <iostream>
using namespace std;

int main() {
	bool student[31] = { false };
	int T = 28;
	while (T--)
	{
		int idx;
		cin >> idx;
		student[idx] = true;
	}
	
	for (int i = 1; i <= 30; i++)
		if (!student[i])
			cout << i << '\n';

	return 0;
}