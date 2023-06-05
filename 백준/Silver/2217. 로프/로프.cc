#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;
	vector<int> rope(N);
	int max = 0; // 로프들의 최대 중량

	for (int i = 0; i < N; i++)
		cin >> rope[i];

	sort(rope.rbegin(), rope.rend()); // 내림차순

	for (int i = 0; i < N; i++)
		if (max < rope[i] * (i + 1))
			max = rope[i] * (i + 1);
	
	cout << max;
	return 0;
}