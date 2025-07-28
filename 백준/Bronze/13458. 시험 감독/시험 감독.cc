#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int A[1000001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, B, C;
    cin >> N;
    
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }
    cin >> B >> C;

    long long ans = 0;
    for (int i = 0; i < N; i++)
    {
        A[i] -= B;
        ans++;

        if (A[i] <= 0) continue;

        int div = A[i] / C;
        ans += div;
        ans += (A[i] % C == 0 ? 0 : 1);
    }

    cout << ans;
    return 0;
}
