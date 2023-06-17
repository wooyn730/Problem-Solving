#include <iostream>
#include <vector>
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> end(N+1);
	int idx = 0;

	for (int i = 666; ; i++)
	{
		if (i % 1000 == 666 || i / 10 % 1000 == 666 || i / 100 % 1000 == 666 || i / 1000 % 1000 == 666)
			end[++idx] = i;
		if (idx == N)
			break;
	}
	cout << end[N];
	return 0;
}