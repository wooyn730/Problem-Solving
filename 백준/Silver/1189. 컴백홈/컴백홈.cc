#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int R, C, K;
bool map[6][6];
bool visited[6][6];
int sum = 0;
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

void Walk(int dis, int i, int j)
{
    if (i == 0 && j == C - 1)
    {
        if (dis == K)
            sum++;
        return;
    }

    for (int l = 0; l < 4; l++)
    {
        int x = i + dx[l];
        int y = j + dy[l];

        if (x < 0 || x > R - 1 || y < 0 || y > C - 1) continue;
        if (!map[x][y] || visited[x][y]) continue;

        visited[x][y] = true;
        Walk(dis + 1, x, y);
        visited[x][y] = false;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> R >> C >> K;

    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            char c;
            cin >> c;
            if (c == '.')
                map[i][j] = true;
            else
                map[i][j] = false;
        }
    }

    visited[R - 1][0] = true;
    Walk(1, R - 1, 0);

    cout << sum;
    return 0;
}