#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int x1, y1, x2, y2, x3, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

    pair<int, int> AB = { x2 - x1, y2 - y1 };
    pair<int, int> BC = { x3 - x2, y3 - y2 };

    int cP = AB.first * BC.second - AB.second * BC.first;

    int ans = cP > 0 ? 1 : cP < 0 ? -1 : 0;
    cout << ans;

    return 0;
}