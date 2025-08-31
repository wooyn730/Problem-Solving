#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int N, M;
vector<int> friends[2001];
bool visited[2001];

void dfs(int fr, int depth)
{
    if (depth == 4)
    {
        cout << 1;
        exit(0);
    }

    for (int i = 0; i < friends[fr].size(); i++)
    {
        int nextFr = friends[fr][i];
        if (!visited[nextFr])
        {
            visited[nextFr] = true;
            dfs(nextFr, depth + 1);
            visited[nextFr] = false;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        friends[a].push_back(b);
        friends[b].push_back(a);
    }

    for (int i = 0; i < N; i++)
    {
        visited[i] = true;
        dfs(i, 0);
        visited[i] = false;
    }

    cout << 0;

    return 0;
}
