#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	string N;
	getline(cin, N); // 공백 포함 문자열
	int UCPC = 0; //0 1 2 3 4
	
	for (char n : N)
	{
		switch (UCPC)
		{
		case 0:
			if (n == 'U')
				UCPC++;
			break;
		case 1:
			if (n == 'C')
				UCPC++;
			break;
		case 2:
			if (n == 'P')
				UCPC++;
			break;
		case 3:
			if (n == 'C')
				UCPC++;
			break;
		}
	}

	if (UCPC == 4)
		cout << "I love UCPC";
	else
		cout << "I hate UCPC";

	return 0;
}