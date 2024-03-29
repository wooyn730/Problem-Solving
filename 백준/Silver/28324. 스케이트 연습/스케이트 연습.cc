#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;
	vector<long long> vec(N);
	vector<long long> vec2(N);

	for (int i = N - 1; i >= 0; i--)
	{
		cin >> vec[i];
	}

	vec2[0] = 1;
	long long sum = 1;
	for (int i = 1; i < N; i++)
	{
		if (vec[i] >= vec2[i - 1] + 1)
			vec2[i] = vec2[i - 1] + 1;
		else if (vec[i] <= vec2[i - 1])
			vec2[i] = vec[i];

		sum += vec2[i];
	}

	cout << sum;
}