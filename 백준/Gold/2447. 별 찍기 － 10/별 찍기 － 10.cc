#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> pattern;

void Draw(int y, int x, int size)
{
    if (size == 1)
    {
        pattern[y][x] = '*';
        return;
    }

    int next = size / 3;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (i == 1 && j == 1) continue;
            Draw(y + i * next, x + j * next, next);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;

    pattern.resize(N, string(N, ' '));
    Draw(0, 0, N);

    for (int i = 0; i < N; i++)
        cout << pattern[i] << "\n";
}
