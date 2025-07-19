#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int X, Y, D, T;
    cin >> X >> Y >> D >> T;

    cout << fixed;
    cout.precision(10);

    double dis = sqrt(pow(X, 2) + pow(Y, 2));
    double ans = dis;

    int cnt = dis / D;
    double jumpDis = cnt * D;
    if (cnt >= 1)
    {
        // 총 거리가 점프거리보다 길 때 

        // 1 집 직전까지 뛰고 남은 거리 걸어가기
        double newDis1 = dis - jumpDis;
        double ans1 = T * cnt + newDis1;

        // 2 1보다 한 번 더 뛰어서 딱 맞춰서 가기
        double ans2 = T * (cnt + 1);
        ans = min(ans, min(ans1, ans2));
    }
    else
    {
        // 점프거리가 총 거리보다 길 때

        // 2번 뛰어서 가기, 1번 뛰고 걸어서 돌아가기, 걸어서만 가기
        ans = min(ans, min((double)T * 2, T - (dis - D)));
    }

    cout << ans;

    return 0;
}