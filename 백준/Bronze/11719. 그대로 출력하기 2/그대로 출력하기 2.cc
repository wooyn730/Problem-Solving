#include <iostream>
#include <string>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string s;

	while(getline(cin, s))
		cout << s << "\n";
}