#include <iostream>
using namespace std;

int result[3], map[2200][2200];

// 단위 종이 내 모든 카들이 모두 같은지 아닌지 판단
bool check(int row, int col, int num) {
	int start = map[row][col];
	for (int i = row; i < row + num; i++) {
		for (int j = col; j < col + num; j++) {
			if (start != map[i][j])
				return false;
		}
	}
	return true;
}

// 9분할로 나눔
void divide(int row, int col, int num) {
	if (check(row, col, num))
		result[map[row][col]]++;
	else
	{
		// 새로운 단위 사이즈 만들기
		int size = num / 3;

		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
				divide(row + size * i, col + size * j, size);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int a;
			cin >> a;
			a++; // -1, 0, 1을 0, 1, 2로 바꾸어 사용
			map[i][j] = a;

		}
	}

	divide(0, 0, N);
	cout << result[0] << '\n' << result[1] << '\n' << result[2];
}