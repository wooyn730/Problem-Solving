#include <iostream>
using namespace std;

int main()
{
	int a[3], b[3];
	for (int i = 0; i < 3; i++)
		cin >> a[i] >> b[i];

	cout << (a[0] == a[1] ? a[2] : (a[0] == a[2] ? a[1] : a[0])) << " "
		<< (b[0] == b[1] ? b[2] : (b[0] == b[2] ? b[1] : b[0]));
	return 0;
}