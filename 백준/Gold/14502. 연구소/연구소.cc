#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
int room[8][8];
vector <pair<int, int>> er;
queue <pair<int, int>> vr;

int dx[] = { 0, 1, 0, -1 };
int dy[] = { -1, 0, 1, 0 };

int safe = 0;

void CheckMaxSafeZone() // BFS
{
    int newRoom[8][8] = { 0 };
    bool visited[8][8] = { false };

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            newRoom[i][j] = room[i][j];

    queue<pair<int, int>> q = vr;

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        if (visited[x][y])
            continue;

        visited[x][y] = true;
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < N && ny >= 0 && ny < M)
            {
                if (newRoom[nx][ny] == 0)
                {
                    newRoom[nx][ny] = 2;
                    q.push({ nx, ny });
                }
            }
        }
    }

    int curSafe = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            if (newRoom[i][j] == 0) curSafe++;

    if (curSafe > safe)
        safe = curSafe;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> room[i][j];
            if (room[i][j] == 0)
                er.push_back({ i, j });
            else if (room[i][j] == 2)
                vr.push({ i, j });
        }
    }
    
    for (int i = 0; i < er.size() - 2; i++)
    {
        for (int j = i + 1; j < er.size() - 1; j++)
        {
            for (int k = j + 1; k < er.size(); k++)
            {
                room[er[i].first][er[i].second] = 1;
                room[er[j].first][er[j].second] = 1;
                room[er[k].first][er[k].second] = 1;
                CheckMaxSafeZone();
                room[er[i].first][er[i].second] = 0;
                room[er[j].first][er[j].second] = 0;
                room[er[k].first][er[k].second] = 0;
            }
        }
    }

    cout << safe;
    return 0;
}
