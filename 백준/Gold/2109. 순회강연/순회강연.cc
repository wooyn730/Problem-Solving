#include <iostream>
#include <queue>
#include<cmath>
using namespace std;

struct cmp
{
    bool operator()(const pair<int, int>& a, const pair<int, int>& b)
    {
        // a의 퍼스트, b의 퍼스트 중에 더 큰게 앞으로 오게 하고
        // 둘이 같다면 a의 세컨드, b의 세컨드 중에 작은게 앞에 오게 하라
        // true면 b, a 순
        if (a.first == b.first)
            return a.second > b.second;

        return a.first < b.first;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
    int maxDay = 0;
    for (int i = 0; i < N; i++)
    {
        int p, d;
        cin >> p >> d;
        pq.push({ p, d });

        if (d > maxDay)
            maxDay = d;
    }

    vector<bool> used(maxDay + 1, false);
    int sum = 0;

    while (!pq.empty())
    {
        int p = pq.top().first;
        int d = pq.top().second;
        pq.pop();
        
        // 늦은 날짜부터 채우기
        for (int day = d; day >= 1; day--)
        {
            if (!used[day])
            {
                used[day] = true;
                sum += p;
                break;
            }
        }
    }
    
    cout << sum;
    return 0;
}
