#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int M, N;
bool num[1000001];

void Eratos(int n)
{
	// 나보다 큰 나의 배수들은 싹 지워줌
	for (int i = n + 1; i <= N; i++)
	{
		if (num[i] && i % n == 0)
			num[i] = false;
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> M >> N;

	for (int i = 2; i <= N; i++)
	{
		num[i] = true;
	}
	
	for (int i = 2; i <= sqrt(N); i++)
	{
		if (num[i])
			Eratos(i);
	}

	for (int i = M; i <= N; i++)
	{
		if (num[i])
			cout << i << "\n";
	}
}