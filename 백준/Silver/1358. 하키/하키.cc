#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int W, H, X, Y, P, x, y, ans = 0;
    cin >> W >> H >> X >> Y >> P;

    while (P--)
    {
        cin >> x >> y;

        if (x >= X && x <= X + W && y >= Y && y <= Y + H)
            ans++;
        else
        {
            double r = (double)H / 2;
            double dis1 = sqrt(pow(X - x, 2) + pow(Y + r - y, 2));
            double dis2 = sqrt(pow(X + W - x, 2) + pow(Y + r - y, 2));

            if (dis1 <= r || dis2 <= r)
                ans++;
        }
    }

    cout << ans;
    return 0;
}