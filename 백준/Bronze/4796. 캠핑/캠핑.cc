#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	for (int i=1; ; i++)
	{
		int L, P, V;
		cin >> L >> P >> V;

		if (V == 0)
			break;

		int d = V / P;
		int max = V / P * L + min(V % P, L);

		cout << "Case " << i <<": " << max << endl;
	}
	return 0;
}