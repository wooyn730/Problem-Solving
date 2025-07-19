#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

struct Enemy
{
    int x, y, r;
};

bool CanCommunicate(const Enemy& a, const Enemy& b)
{
    double dis = sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
    return double(a.r + b.r) >= dis;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T, N, x, y, r;
    cin >> T;

    while (T--)
    {
        cin >> N;

        vector<Enemy> enemies(N);
        for (int i = 0; i < N; i++)
        {
            cin >> x >> y >> r;
            enemies[i] = { x, y, r };
        }

        vector<bool> visited(N, false);
        int ans = 0;
        for (int i = 0; i < N; i++)
        {
            if (!visited[i])
            {
                ans++;
                queue<int> q;
                visited[i] = true;
                q.push(i);

                while (!q.empty())
                {
                    int current = q.front();
                    q.pop();

                    for (int j = 0; j < N; j++)
                    {
                        if (!visited[j] && CanCommunicate(enemies[current], enemies[j]))
                        {
                            visited[j] = true;
                            q.push(j);
                        }
                    }
                }
            }
        }

        cout << ans << "\n";
    }
    
    return 0;
}