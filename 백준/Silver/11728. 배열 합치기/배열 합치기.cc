#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	cin >> N >> M;
	vector<int> vec(N+M);

	for (int i = 0; i < N + M; i++)
		cin >> vec[i];

	sort(vec.begin(), vec.end());

	for (int i = 0; i < N + M; i++)
		cout << vec[i] << " ";
}