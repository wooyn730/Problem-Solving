#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

pair<int, int> stickers[101];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int H, W, N, ans = 0;
    cin >> H >> W >> N;

    for (int i = 0; i < N; i++)
    {
        int R, C;
        cin >> R >> C;
        stickers[i] = { R, C };
    }

    // H W 모눈종이에 겹치지 않게 붙일 수 있는 가장 큰 스티커 2장의 면적
    // 모든 스티커를 조합
    for (int i = 0; i < N - 1; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            // 두 스티커의 면적의 합
            int newAns = stickers[i].first * stickers[i].second + stickers[j].first * stickers[j].second;

            if (newAns <= ans)
                continue;
            if (newAns > W * H)
                continue;

            bool isAble = false;

            // 두 스티커를 붙인다
            // 가로합과 세로합을 구한다
            // 가로세로가 HW or WH보다 같거나 작으면 된다
            int sumX = stickers[i].first + stickers[j].first;
            int sumY = stickers[i].second + stickers[j].second;
            int biggerX = max(stickers[i].first, stickers[j].first);
            int biggerY = max(stickers[i].second, stickers[j].second);
            if ((sumX <= W && biggerY <= H) || (sumY <= W && biggerX <= H) ||
                (sumX <= H && biggerY <= W) || (sumY <= H && biggerX <= W))
                isAble = true;

            // 안되면 한 스티커를 회전시키고 체크해본다.
            sumX = stickers[i].first + stickers[j].second;
            sumY = stickers[i].second + stickers[j].first;
            biggerX = max(stickers[i].first, stickers[j].second);
            biggerY = max(stickers[i].second, stickers[j].first);
            if ((sumX <= W && biggerY <= H) || (sumY <= W && biggerX <= H) ||
                (sumX <= H && biggerY <= W) || (sumY <= H && biggerX <= W))
                isAble = true;

            if (isAble)
                ans = newAns;
        }
    }

    cout << ans;
    return 0;
}