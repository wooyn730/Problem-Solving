#include <iostream>
#include <vector>
using namespace std;

int map[21][21];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M, x, y, K;
    cin >> N >> M >> x >> y >> K;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> map[i][j];

    // 동, 서, 북, 남
    int dx[4] = { 0, 0, -1, 1 };
    int dy[4] = { 1, -1, 0, 0 };

    vector<int> dice(6);
    // 0: 윗면
    // 5: 아랫면

    for (int i = 0; i < K; i++) {
        int com;
        cin >> com;

        int newX = x + dx[com - 1];
        int newY = y + dy[com - 1];
        if (newX < 0 || newX >= N || newY < 0 || newY >= M)
            continue;
        x = newX;
        y = newY;

        vector<int> newDice(6);
        switch (com)
        {
        case 1: // 동
            newDice[0] = dice[3];
            newDice[1] = dice[0];
            newDice[2] = dice[2];
            newDice[3] = dice[5];
            newDice[4] = dice[4];
            newDice[5] = dice[1];
            break;
        case 2: // 서
            newDice[0] = dice[1];
            newDice[1] = dice[5];
            newDice[2] = dice[2];
            newDice[3] = dice[0];
            newDice[4] = dice[4];
            newDice[5] = dice[3];
            break;
        case 3: // 북
            newDice[0] = dice[4];
            newDice[1] = dice[1];
            newDice[2] = dice[0];
            newDice[3] = dice[3];
            newDice[4] = dice[5];
            newDice[5] = dice[2];
            break;
        case 4: // 남
            newDice[0] = dice[2];
            newDice[1] = dice[1];
            newDice[2] = dice[5];
            newDice[3] = dice[3];
            newDice[4] = dice[0];
            newDice[5] = dice[4];
            break;
        }
        dice = newDice;

        if (map[x][y] != 0) {
            dice[5] = map[x][y];
            map[x][y] = 0;
        }
        else {
            map[x][y] = dice[5];
        }

        cout << dice[0] << "\n";
    }

    return 0;
}