#include <iostream>
#include <string>
using namespace std;

int main(void)
{
    int N;
    cin >> N;
    int big[50][2] = { 0, 0 };


    for (int i = 0; i < N; i++)
    {
        cin >> big[i][0] >> big[i][1];
    }

    for (int i = 0; i < N; i++)
    {
        int cnt = 1;
        for (int j = 0; j < N; j++)
        {
            if ((big[i][0] < big[j][0]) && (big[i][1] < big[j][1]))
                cnt++;
        }
        cout << cnt;
        if (i!=N-1)
            cout << " ";
    }

}