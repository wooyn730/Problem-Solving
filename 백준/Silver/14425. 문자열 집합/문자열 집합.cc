#include <iostream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    unordered_set<string> S;
    while (N--)
    {
        string s;
        cin >> s;
        S.insert(s);
    }

    int cnt = 0;
    while (M--)
    {
        string s;
        cin >> s;

        if (S.find(s) != S.end())
            cnt++;
    }

    cout << cnt;
    return 0;
}
