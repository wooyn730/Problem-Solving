#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // 출발지에서 목적지로 갈 때 꼭 해당 원을 지나야 하는가?
    // 만약 그렇다면 +1
    // 출발지와 목적지가 원 안에 있는지만 체크하면 됨
    // 하지만 두 지점 모두 같은 원 안에 있다면 체크 ㄴㄴ

    int T;
    cin >> T;
    while (T--)
    {
        int ans = 0;

        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            int cx, cy, cr;
            cin >> cx >> cy >> cr;

            // 출발지와 원 중심의 거리가 cr 이하인지
            float dis1 = sqrt(pow(x1 - cx, 2) + pow(y1 - cy, 2));
            
            // 목적지와 원 중심의 거리가 cr 이하인지
            float dis2 = sqrt(pow(x2 - cx, 2) + pow(y2 - cy, 2));

            if ((dis1 <= cr && dis2 > cr) || (dis1 > cr && dis2 <= cr))
                ans++;
        }

        cout << ans << "\n";
    }

    return 0;
}