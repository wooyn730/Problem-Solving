#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	int N, L;
	cin >> N >> L;
	int h[100001];
	
	for (int i = 0; i < N; i++)
		cin >> h[i];

	sort(h, h + N);
	
	for (int i = 0; i < N; i++)
	{
		if (L >= h[i])
			L++;
		else
			break;
	}

	cout << L;
	return 0;
}