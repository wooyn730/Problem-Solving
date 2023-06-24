#include <iostream>
using namespace std;

char s[5][15];

int main() {

    for (int i = 0; i < 5; i++)
        cin >> s[i];

    for (int i = 0; i < 15; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (s[j][i])
                cout << s[j][i];
        }
    }
}