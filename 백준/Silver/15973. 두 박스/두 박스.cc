#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int x1, y1, x2, y2; // 왼쪽 아래, 오른쪽 위
    int x3, y3, x4, y4;
    cin >> x1 >> y1 >> x2 >> y2;
    cin >> x3 >> y3 >> x4 >> y4;

    if (x3 > x2 || y2 < y3 || x4 < x1 || y1 > y4)
        cout << "NULL";
    else if ((x1 == x4 && y1 == y4) || (x3 == x2 && y1 == y4) ||
        (x2 == x3 && y2 == y3) || (x1 == x4 && y2 == y3))
        cout << "POINT";
    else if (x1 == x4 || x2 == x3 || y1 == y4 || y2 == y3)
        cout << "LINE";
    

    return 0;
}