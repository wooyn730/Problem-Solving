#include <iostream>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;

bool visited[2001][2001]; // num, save

void Emoji(int target)
{
    queue<pair<pair<int, int>, int>> q; // {{숫자, 복사해둔 수}, 시간}
    q.push({ { 1, 0 }, 0 });
    visited[1][0] = true;

    while (!q.empty())
    {
        int num = q.front().first.first;
        int save = q.front().first.second;
        int time = q.front().second;
        q.pop();

        if (num == target)
        {
            cout << time;
            exit(0);
        }

        if (!visited[num][num])
        {
            visited[num][num] = true;
            q.push({ { num, num }, time + 1 });
        }

        if (num + save <= 2000 && !visited[num + save][save])
        {
            visited[num + save][save] = true;
            q.push({ { num + save, save }, time + 1 });
        }

        if (num > 0 && !visited[num - 1][save])
        {
            visited[num - 1][save] = true;
            q.push({ { num - 1, save }, time + 1 });
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int S;
    cin >> S;

    Emoji(S);

    return 0;
}
