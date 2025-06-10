#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int R, C, ZR, ZC;
    cin >> R >> C >> ZR >> ZC;

    string ans, s;
    for (int i = 0; i < R; i++)
    {
        cin >> s;

        string newS;

        for (int j = 0; j < C; j++)
            for (int k = 0; k < ZC; k++)
                newS += s[j];
        newS += "\n";
        for (int l = 0; l < ZR; l++)
            ans += newS;
    }

    cout << ans << "\n";

    return 0;
}
