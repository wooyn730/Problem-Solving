#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int K, T = 6;
    cin >> K;

    vector<pair<int, int>> vec(T);
    for (int i = 0; i < T; i++)
    {
        int dir, width;
        cin >> dir >> width;
        vec[i] = { dir, width };
    }

    int s;
    for (int i = 0; i < T; i++)
    {
        if (vec[i].first == vec[(i + 2) % T].first && vec[(i + 1) % T].first == vec[(i + 3) % T].first)
        {
            s = i;
            break;
        }
    }

    int ans = (vec[(s + 4) % T].second * vec[(s + 5) % T].second) - (vec[(s + 1) % T].second * vec[(s + 2) % T].second);
    cout << ans * K;

    return 0;
}