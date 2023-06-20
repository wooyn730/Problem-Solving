#include <iostream>
#include <vector>
using namespace std;

int main() {
	int N, M;
	cin >> N >> M;
	vector<int> basket;

	for (int i = 0; i <= N; i++)
		basket.push_back(i);

	while (M--)
	{
		int i = 0, j = 0;
		cin >> i >> j;

		int tmp = basket[i];
		basket[i] = basket[j];
		basket[j] = tmp;
	}

	for (int i = 1; i <= N; i++)
		cout << basket[i] << " ";
	return 0;
}