#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	int N, ans = 1;
	cin >> N;
	char seat[51];

	for (int i=0; i<N; i++)
	{
		cin >> seat[i];
	}

	for (int i = 0; i < N; i++)
	{
		ans++;

		if (seat[i] == 'L')
			i++;
	}
	cout << (ans > N ? N : ans);

	return 0;
}