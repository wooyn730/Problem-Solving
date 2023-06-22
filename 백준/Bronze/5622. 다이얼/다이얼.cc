#include <iostream>
using namespace std;

int main() {
	string s;
	cin >> s;
	int sec = 0;
	for (char a : s)
	{
		if (a <= 'C')
			sec += 3;
		else if (a <= 'F')
			sec += 4;
		else if (a <= 'I')
			sec += 5;
		else if (a <= 'L')
			sec += 6;
		else if (a <= 'O')
			sec += 7;
		else if (a <= 'S')
			sec += 8;
		else if (a <= 'V')
			sec += 9;
		else if (a <= 'Z')
			sec += 10;
	}
	cout << sec;
	return 0;
}