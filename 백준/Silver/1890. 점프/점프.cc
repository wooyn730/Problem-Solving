#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int board[101][101];
long long route[101][101]; // route[a][b] == (a, b)칸에 도달할 수 있는 수

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> board[i][j];
        }
    }

    route[0][0] = 1;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            int jump = board[i][j];

            if (jump == 0)
                continue;

            if (i + jump < N)
                route[i + jump][j] += route[i][j];
            if (j + jump < N)
                route[i][j + jump] += route[i][j];
        }
    }

    cout << route[N - 1][N - 1];

    return 0;
}