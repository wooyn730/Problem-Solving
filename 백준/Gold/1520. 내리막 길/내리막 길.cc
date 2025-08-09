#include <iostream>
using namespace std;

int M, N;
int map[501][501];
long long visit[501][501];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

long long dfs(int x, int y) {
    if (x == M - 1 && y == N - 1)
        return 1;

    if (visit[x][y] != -1)
        return visit[x][y];

    visit[x][y] = 0;

    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && nx < M && ny >= 0 && ny < N)
        {
            if (map[nx][ny] < map[x][y])
            {
                visit[x][y] += dfs(nx, ny);
            }
        }
    }

    return visit[x][y];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> M >> N;

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> map[i][j];
            visit[i][j] = -1;
        }
    }

    cout << dfs(0, 0);

    return 0;
}
