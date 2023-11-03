#include <iostream>
#include <string>
#include <map>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	cin >> N >> M;
	map<string, string> password;

	string site, pwd;

	while (N--)
	{
		cin >> site >> pwd;

		password.insert({ site, pwd });
	}

	while (M--)
	{
		cin >> site;
		cout << password[site] << "\n";
	}
}