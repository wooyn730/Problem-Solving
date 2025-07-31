#include<iostream>
#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

vector<string> s;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string S;
    cin >> S;

    for (int i = 0; i < S.length(); i++)
    {
        for (int j = 1; j <= S.length() - i; j++)
        {
            s.push_back(S.substr(i, j));
        }
    }

    sort(s.begin(), s.end());
    s.erase(unique(s.begin(), s.end()), s.end());

    cout << s.size();
    return 0;
}
