#include <iostream>
using namespace std;

long long returnVal(string s)
{
	if (s == "black")
		return 0;
	else if (s == "brown")
		return 1;
	else if (s == "red")
		return 2;
	else if (s == "orange")
		return 3;
	else if (s == "yellow")
		return 4;
	else if (s == "green")
		return 5;
	else if (s == "blue")
		return 6;
	else if (s == "violet")
		return 7;
	else if (s == "grey")
		return 8;
	else if (s == "white")
		return 9;
}

long long returnMul(string s)
{
	if (s == "black")
		return 1;
	else if (s == "brown")
		return 10;
	else if (s == "red")
		return 100;
	else if (s == "orange")
		return 1000;
	else if (s == "yellow")
		return 10000;
	else if (s == "green")
		return 100000;
	else if (s == "blue")
		return 1000000;
	else if (s == "violet")
		return 10000000;
	else if (s == "grey")
		return 100000000;
	else if (s == "white")
		return 1000000000;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	long long ans = 0;
	
	for (int i = 0; i < 3; i++)
	{
		string s;
		cin >> s;

		if (i < 2)
			ans = ans * 10 + returnVal(s);
		else
			ans *= returnMul(s);
	}

	cout << ans;
}