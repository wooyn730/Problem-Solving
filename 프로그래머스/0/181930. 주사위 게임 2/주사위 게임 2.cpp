#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int a, int b, int c) {
    int answer = 1;
    int mode = 1;
    if (a == b && b == c)
        mode = 3;
    else if (a == b || b == c || a == c)
        mode = 2;
    
    for (int i=1; i<=mode; i++)
    {
        int a2 = pow(a, i);
        int b2 = pow(b, i);
        int c2 = pow(c, i);
        answer *= (a2+b2+c2);
    }
    return answer;
}