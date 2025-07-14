#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

pair<int, int> cp[100001];
int len[100001];
int sum;
int minAns;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int x, y;
        cin >> x >> y;
        cp[i] = { x, y };

        if (i > 0)
        {
            len[i] = abs(cp[i].first - cp[i - 1].first) + abs(cp[i].second - cp[i - 1].second);
            sum += len[i];
        }
    }

    minAns = sum;

    for (int i = 1; i < N - 1; i++)
    {
        // len[1]은 0번 지점에서 1번 지점까지의 거리
        // 건너 뛸 지점이 1일 때, 총합에서 0-1 거리와 1-2 거리를 빼고 0-2 거리를 더한다
        double newLen = abs(cp[i - 1].first - cp[i + 1].first) + abs(cp[i - 1].second - cp[i + 1].second);
        double newSum = sum - len[i] - len[i + 1] + newLen;

        if (newSum < minAns)
            minAns = newSum;
    }

    cout << minAns;

    return 0;
}