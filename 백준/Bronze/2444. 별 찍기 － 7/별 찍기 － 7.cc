#include <iostream>
using namespace std;

int main()
{
    int N;
    cin >> N;

    // 윗 삼각형
    for (int i = 1; i <= N; i++)
    {
        // 좌
        for (int j = 1; j <= N; j++)
        {
            if (j <= N - i)
                cout << " ";
            else
                cout << "*";
        }

        // 우
        for (int k = 1; k < i; k++)
        {
            cout << "*";
        }

        cout << '\n';
    }

    // 아래 삼각형
    for (int i = 1; i <= N - 1; i++)
    {
        // 좌
        for (int j = 1; j <= N; j++)
        {
            if (j <= i)
                cout << " ";
            else
                cout << "*";
        }

        // 우
        for (int k = 1; k <= N - i - 1; k++)
        {
            cout << "*";
        }

        cout << '\n';
    }
}