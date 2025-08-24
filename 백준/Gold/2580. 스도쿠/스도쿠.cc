#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int sudoku[9][9];
vector<pair<int, int>> blanks;

void LetsSudoku(int idx)
{
    if (idx == blanks.size())
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                cout << sudoku[i][j] << " ";
            }
            cout << "\n";
        }
        exit(0);
    }

    bool possibleNum[10];
    for (int i = 1; i <= 9; i++)
        possibleNum[i] = true;

    int x = blanks[idx].first;
    int y = blanks[idx].second;
    for (int i = 0; i < 9; i++)
    {
        if (sudoku[x][i] != 0)
            possibleNum[sudoku[x][i]] = false;
        if (sudoku[i][y] != 0)
            possibleNum[sudoku[i][y]] = false;
        // 0 1 2 3 4 5 6 7 8
        // 0 1 2 0 1 2 0 1 2 - 3으로 나눈 나머지
        // 0 0 0 1 1 1 2 2 2 - 3으로 나눈 몫
    }
    for (int i = (x / 3) * 3; i < (x / 3) * 3 + 3; i++)
    {
        for (int j = (y / 3) * 3; j < (y / 3) * 3 + 3; j++)
        {
            if (sudoku[i][j] != 0)
                possibleNum[sudoku[i][j]] = false;
        }
    }
    for (int i = 1; i <= 9; i++)
    {
        if (possibleNum[i])
        {
            sudoku[x][y] = i;
            LetsSudoku(idx + 1);
            sudoku[x][y] = 0;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cin >> sudoku[i][j];
            if (sudoku[i][j] == 0)
                blanks.push_back({ i, j });
        }
    }
    
    LetsSudoku(0);

    return 0;
}
