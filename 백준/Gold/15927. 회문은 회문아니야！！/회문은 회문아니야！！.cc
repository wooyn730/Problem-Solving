#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int len = 0;

bool CheckPalindrom(string str)
{
    for (int i = 0; i < len / 2; i++)
    {
        if (str[i] != str[len - 1 - i])
            return false;
    }
    return true;
}

bool CheckAllSame(string str)
{
    for (int i = 0; i < len / 2; i++)
    {
        if (str[i] != str[i + 1])
            return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;
    len = s.length();

    if (!CheckPalindrom(s)) // 펠린드롬 아님
    {
        cout << len;
    }
    else
    {
        if (CheckAllSame(s))
            cout << -1;
        else
            cout << len - 1;
    }

    return 0;
}