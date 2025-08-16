#include <iostream>
#include <queue>
#include <cmath>
#include <algorithm>
using namespace std;

struct Gem {
    int m, v; // 무게, 가격
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K;
    cin >> N >> K;

    vector<Gem> gems(N);
    vector<int> bags(K);

    for (int i = 0; i < N; i++)
        cin >> gems[i].m >> gems[i].v;
    for (int i = 0; i < K; i++)
        cin >> bags[i];

    // 보석 무게 오름차순
    sort(gems.begin(), gems.end(), [](auto& a, auto& b) {
        return a.m < b.m;
        });
    // 가방 무게 오름차순
    sort(bags.begin(), bags.end());

    priority_queue<int> pq; // 가격 max heap
    long long sum = 0;
    int idx = 0;

    for (int i = 0; i < K; i++)
    {
        while (idx < N && gems[idx].m <= bags[i])
        {
            // 가장 작은 가방부터
            // 현재 넣을 수 있는 모든 보석(후보) 넣기
            pq.push(gems[idx].v);
            idx++;
        }

        // 가장 높은 가격의 보석만 넣고 나머지는 다음 가방 후보
        if (!pq.empty())
        {
            sum += pq.top();
            pq.pop();
        }
    }
    cout << sum;
    return 0;
}