#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int priority[101];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    while (T--)
    {
        int N, M;
        cin >> N >> M;

        queue<pair<int, int>> docs;
        queue<int> prior;

        for (int i = 0; i < N; i++)
        {
            cin >> priority[i];
            docs.push({ i, priority[i] });
        }

        sort(priority, priority + N, greater<int>());
        for (int i = 0; i < N; i++)
        {
            prior.push(priority[i]);
        }

        int cnt = 0;
        while (!docs.empty())
        {
            if (docs.front().second == prior.front())
            {
                cnt++;
                if (docs.front().first == M)
                    break;
                prior.pop();
            }
            else
            {
                docs.push(docs.front());
            }
            docs.pop();
        }
        cout << cnt << "\n";
    }
    return 0;
}
