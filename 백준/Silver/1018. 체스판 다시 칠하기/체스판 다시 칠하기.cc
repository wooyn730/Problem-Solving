#include <iostream>
#include <string>
using namespace std;

int main(void)
{
    int M, N;
    cin >> M >> N;

    char chess[50][50] = { 0 };
    int overcoat = 64;
    
    for (int i = 0; i < M; i++) // 세로
    {
        for (int j = 0; j < N; j++) // 가로
        {
            cin >> chess[i][j];
        }
    }

    // 첫칸이 검은색일때 적게 덧칠하는지 흰색일때 적게 덧칠하는지
    // 8*8로 자르는 경우의 수 중 어떨 때 적게 덧칠하는지
    for (int a = 0; a <= M-8; a++)
    {
        for (int b = 0; b <= N - 8; b++)
        {
            int firstB = 0; // 첫칸이 검은색(검은색=x+y가 짝수)일 때 덧칠해야하는 수
            int firstW = 0; // 첫칸이 흰색(검은색=x+y가 홀수)일 때

            for (int i = a; i < a + 8; i++)
            {
                for (int j = b; j < b + 8; j++)
                {
                    if (chess[i][j] == 'B')
                    {
                        if ((i + j) % 2 == 0) // 좌표값이 짝수이고 검은색
                        {
                            firstW++;
                            //cout << chess[i][j] <<'\n';
                        }
                        else
                            firstB++; // (검, 짝) 기준 (검, 짝)이 아닐때 덧칠
                    }
                    else
                    {
                        if ((i + j) % 2 == 0) // 좌표값이 짝수이고 흰색
                            firstB++; // (검, 짝) 기준 (흰, 짝)이면 덧칠
                        else
                        {
                            firstW++;
                            //cout << chess[i][j] << '\n';
                        }
                    }
                }
            }
            //cout << firstB << " " << firstW << '\n';
            overcoat = ((firstB < firstW) ? (firstB < overcoat ? firstB : overcoat) : (firstW < overcoat ? firstW : overcoat));
        }
    }
    cout << overcoat;
}