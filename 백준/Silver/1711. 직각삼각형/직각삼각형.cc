#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

pair<int, int> dots[1501];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, x, y, ans = 0;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> x >> y;
        dots[i] = { x, y };
    }

    long long len1, len2, len3;
    for (int i = 0; i < N - 2; i++)
    {
        for (int j = i + 1; j < N - 1; j++)
        {
            for (int k = j + 1; k < N; k++)
            {
                long long straight = (dots[j].first - dots[i].first) * (dots[k].second - dots[i].second)
                    - (dots[j].second - dots[i].second) * (dots[k].first - dots[i].first);
                if (straight == 0) continue;

                long long newX, newY;
                newX = dots[i].first - dots[j].first;
                newY = dots[i].second - dots[j].second;
                len1 = newX * newX + newY * newY;

                newX = dots[i].first - dots[k].first;
                newY = dots[i].second - dots[k].second;
                len2 = newX * newX + newY * newY;

                newX = dots[j].first - dots[k].first;
                newY = dots[j].second - dots[k].second;
                len3 = newX * newX + newY * newY;

                if (len1 == len2 + len3 || len2 == len1 + len3 || len3 == len1 + len2)
                    ans++;
            }
        }
    }

    cout << ans;
    return 0;
}