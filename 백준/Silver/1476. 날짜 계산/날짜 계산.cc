#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	
	int E, S, M;
	cin >> E >> S >> M;
	
	E = E == 15 ? 0 : E;
	S = S == 28 ? 0 : S;
	M = M == 19 ? 0 : M;
	
	int min = (E < S ? (E < M ? E : M) : (S < M ? S : M));
	if (min == 0)
		min = 1;

	for (int i = min; ; i++)
	{
		if (i % 15 == E && i % 28 == S && i % 19 == M)
		{
			cout << i;
			break;
		}
	}
	return 0;
}