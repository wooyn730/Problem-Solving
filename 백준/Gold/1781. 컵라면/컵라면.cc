#include <iostream>
#include <queue>
#include <cmath>
#include <algorithm>
using namespace std;

struct Problem {
    int d, c; // 데드라인, 컵라면
};

struct cmp
{
    bool operator()(const Problem& a, const Problem& b)
    {
        if (a.d != b.d)
            return a.d < b.d;
        return a.c > b.c;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    vector<Problem> a;

    for (int i = 0; i < N; i++)
    {
        int d, c;
        cin >> d >> c;
        a.push_back({ d, c });
    }

    sort(a.begin(), a.end(), cmp());

    // 최소 힙, 작은 것이 앞(오름차순)
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < a.size(); i++)
    {
        pq.push(a[i].c);
        if (pq.size() > a[i].d)
            pq.pop();
        // 가장 적은 컵라면 문제 풀지 않기
    }

    long long sum = 0;
    while (!pq.empty())
    {
        sum += pq.top();
        pq.pop();
    }
    cout << sum;
    return 0;
}
