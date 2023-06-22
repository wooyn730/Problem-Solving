#include <iostream>
using namespace std;

int main() {
	char a;
	cin >> a;

	if (a >= 'A' && a <= 'Z')
		cout << a - 'A' + 'A';
	else if (a >= 'a' && a <= 'z')
		cout << a - 'a' + 'a';
	else if (a >= '0' && a <= '9')
		cout << a - '0' + '0';
	return 0;
}