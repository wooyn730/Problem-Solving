#include <iostream>
using namespace std;

int main()
{
    int N;
    cin >> N;
    int b = 0; // 봉지 수

    while (N >= 0)
    {
        if (N % 5 == 0)
        {
            cout << N / 5 + b;
            return 0;
        }
        N -= 3;
        b++;
    }
    cout << -1;
}