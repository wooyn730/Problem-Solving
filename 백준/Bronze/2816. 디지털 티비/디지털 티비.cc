#include <iostream>
using namespace std;

string channel[100];

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;
	int idx1 = 0, idx2 = 0;

	for (int i = 0; i < N; i++)
	{
		cin >> channel[i];
		if (channel[i] == "KBS1")
			idx1 = i;
		else if (channel[i] == "KBS2")
			idx2 = i;
	}

	string ans = "";

	for (int i = 0; i < idx1; i++)
		ans += "1";
	for (int i = idx1; i > 0; i--)
		ans += "4";

	
	for (int i = 0; i < idx2; i++)
		ans += "1";
	if (idx1 > idx2)
		ans += "14";
	for (int i = idx2; i > 1; i--)
		ans += "4";

	cout << ans;
}