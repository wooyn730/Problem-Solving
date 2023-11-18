#include <iostream>
#include <algorithm>
using namespace std;

int arr[100000];

 int BinarySearch(int size, int num)
{
	int start = 0;
	int end = size - 1;
	int mid;

	while (end >= start)
	{
		mid = (start + end) / 2;

		if (arr[mid] == num)
			return 1;
		else if (arr[mid] > num)
			end = mid - 1;
		else if (arr[mid] < num)
			start = mid + 1;
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
	{
		cin >> arr[i];
	}

	sort(arr, arr + N);

	cin >> M;
	while (M--)
	{
		cin >> num;
		cout << BinarySearch(N, num) << "\n";
	}
}