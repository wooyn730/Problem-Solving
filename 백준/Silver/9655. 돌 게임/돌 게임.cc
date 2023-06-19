#include <iostream>
using namespace std;

int main() {
	int N;
	cin >> N;
	int turn = 0;
	
	while (N)
	{
		turn++;
		if (N >= 3)
			N -= 3;
		else
			N--;
	}
	
	cout << ((turn % 2 == 0) ? "CY" : "SK");
	return 0;
}