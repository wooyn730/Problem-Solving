#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int alphabet[26] = { 0 };

    char c;
    while (cin >> c)
    {
        if (c != ' ')
            alphabet[c - 'a']++;
    }

    int max = 0;
    for (int i = 0; i < 26; i++)
    {
        if (alphabet[i] > max)
            max = alphabet[i];
    }

    for (int i = 0; i < 26; i++)
    {
        if (alphabet[i] == max)
            cout << char('a' + i);
    }

    return 0;
}
