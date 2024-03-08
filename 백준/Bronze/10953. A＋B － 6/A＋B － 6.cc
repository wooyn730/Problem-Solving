#include <iostream>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;

	while (T--)
	{
		string s;
		cin >> s;
		int A = s[0] - '0';
		int B = s[2] - '0';
		cout << A + B << "\n";
	}
}