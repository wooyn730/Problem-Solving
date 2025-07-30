#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>
using namespace std;

bool apple[101][101];
int turn[10001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K, L;
    cin >> N >> K;

    for (int i = 0; i < K; i++)
    {
        int y, x;
        cin >> y >> x;
        apple[y - 1][x - 1] = true;
    }

    cin >> L;
    for (int i = 0; i < L; i++)
    {
        int x;
        char c; // L 왼쪽 D 오른쪽 회전 // 1 왼 2 오
        cin >> x >> c;
        turn[x] = c == 'L' ? 1 : 2;
    }

    int time = 0;
    int posX = 0;
    int posY = 0;
    int dir = 1; // 0 상 1 우 2 하 3 좌
    deque<pair<int, int>> snake;
    snake.push_back({ 0, 0 });
    while (true)
    {
        time++;
        
        bool isDead = false;
        switch (dir)
        {
        case 0:
            posY -= 1;
            if (posY < 0)
                isDead = true;
            break;
        case 1:
            posX += 1;
            if (posX >= N)
                isDead = true;
            break;
        case 2:
            posY += 1;
            if (posY >= N)
                isDead = true;
            break;
        case 3:
            posX -= 1;
            if (posX < 0)
                isDead = true;
            break;
        }
        if (isDead)
            break;

        for (auto s : snake) {
            if (s.first == posY && s.second == posX) {
                isDead = true;
                break;
            }
        }

        if (isDead)
            break;

        snake.push_back({ posY , posX });

        if (apple[posY][posX])
            apple[posY][posX] = false;
        else
            snake.pop_front();

        if (turn[time] == 1)
            dir = (dir + 3) % 4;
        else if (turn[time] == 2)
            dir = (dir + 1) % 4;
    }

    cout << time;
    return 0;
}
