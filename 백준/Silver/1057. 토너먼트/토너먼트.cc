#include <iostream>
using namespace std;

int main() {
	int N, jimin, hansu;
	cin >> N >> jimin >> hansu;
	int round = 0;
	
	if (jimin > hansu)
	{
		int tmp = hansu;
		hansu = jimin;
		jimin = tmp;
	}
	while (true)
	{
		round++;
		if (jimin % 2 == 1 && jimin + 1 == hansu)
			break;
		else
		{
			if (jimin % 2 != 0) jimin++;
			jimin /= 2;

			if (hansu % 2 != 0) hansu++;
			hansu /= 2;
		}
	}
	
	cout << round;
	return 0;
}