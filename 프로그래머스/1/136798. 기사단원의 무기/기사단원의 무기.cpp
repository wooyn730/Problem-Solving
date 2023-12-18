#include <string>
#include <vector>
#include <cmath>
using namespace std;

int solution(int number, int limit, int power) {
    int answer = 0;
    int divisor;
    for (int i=1; i<=number; i++)
    {
        divisor = 0;
        
        for (int j=1; j<=sqrt(i); j++)
            if (i%j == 0)
            {
                if (j*j == i)
                    divisor++;
                else
                    divisor += 2;
            }
        
        answer += (divisor > limit ? power : divisor);
    }
    
    return answer;
}