#include <iostream>
#include <queue>
#include<cmath>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < N; i++)
    {
        int x;
        cin >> x;
        pq.push(x);
    }

    int sum = 0;
    for (int i = 0; i < N - 1; i++)
    {
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();
        int c = a + b;
        sum += c;
        pq.push(c);
    }
    cout << sum;
    return 0;
}
