#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	string N;
	cin >> N;

	sort(N.rbegin(), N.rend());

	if (N[N.length()-1] != '0')
		cout << -1;
	else
	{
		long long num = 0;
		for (auto o : N)
			num += o - '0';
		
		if (num % 3 == 0)
			cout << N;
		else
			cout << -1;
	}
	return 0;
}