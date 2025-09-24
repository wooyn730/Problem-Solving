#include <iostream>
#include <string>
using namespace std;

// https://donggoolosori.github.io/2020/09/27/boj-1992/
string video[64];

// 재귀함수
void Compression(int size, int y, int x)
{
	char curr = video[y][x];

	for (int i=y; i<y+size; i++)
		for (int j=x; j<x+size; j++)
			if (video[i][j] != curr)
			{
				cout << '(';
				Compression(size / 2, y, x);
				Compression(size / 2, y, x+size/2);
				Compression(size / 2, y+size/2, x);
				Compression(size / 2, y + size / 2, x + size / 2);
				cout << ')';
				return;
			}
	cout << curr;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> video[i];
	Compression(N, 0, 0);
}