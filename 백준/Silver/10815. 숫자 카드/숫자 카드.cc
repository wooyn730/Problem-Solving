#include <iostream>
#include <algorithm>
using namespace std;

int arr[500000];

int BinarySearch(int size, int num)
{
	int s = 0;
	int e = size - 1;
	int m;

	while (s <= e)
	{
		m = (s + e) / 2;
		if (arr[m] == num)
			return 1;
		else if (arr[m] > num)
			e = m - 1;
		else if (arr[m] < num)
			s = m + 1;
	}
	return 0;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M, num;
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	sort(arr, arr + N);

	cin >> M;
	while (M--)
	{
		cin >> num;
		cout << BinarySearch(N, num) << " ";
	}
}