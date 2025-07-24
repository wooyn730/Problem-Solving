#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

queue<int> nums;
int ans[5001];
int cnt;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K;
    cin >> N >> K;

    for (int i = 1; i <= N; i++)
        nums.push(i);

    while (!nums.empty())
    {
        for (int i = 0; i < K - 1; i++)
        {
            nums.push(nums.front());
            nums.pop();
        }
        ans[cnt++] = nums.front();
        nums.pop();
    }

    cout << "<";
    for (int i = 0; i < N; i++)
    {
        cout << ans[i];
        if (i != N - 1)
            cout << ", ";
    }
    cout << ">";

    return 0;
}