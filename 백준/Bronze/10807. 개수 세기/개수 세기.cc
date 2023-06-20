#include <iostream>
using namespace std;

int main() {
	int N, num[101], v, cnt = 0;
	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> num[i];
	cin >> v;

	for (int i = 0; i < N; i++)
		if (num[i] == v)
			cnt++;

	cout << cnt;
	return 0;
}