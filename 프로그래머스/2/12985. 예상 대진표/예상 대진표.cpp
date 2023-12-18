#include <algorithm> // swap

using namespace std;

int solution(int n, int a, int b)
{
    int answer = 0;
    
    while (true)
    {
        answer++;
        
        // 작은 수가 홀수, 큰 수가 짝수이면서 1 차이
        if (a > b)
            swap(a, b);
        if (a%2==1 && a+1==b)
           return answer;
        
        if (a%2 != 0)
            a++;
        if (b%2 != 0)
            b++;
        
        a /= 2;
        b /= 2;
    }
    
}
