#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer(2);
    
    for (int i=1; i<=sqrt(brown+yellow); i++)
    {
        if ((brown+yellow)%i != 0)
            continue;
        
        int a1 = i;
        int a2 = (brown+yellow)/i;
        
        if ((brown == (a1-1+a2-1)*2) && (yellow == (a1-2)*(a2-2)))
        {
            answer[0] = (a1 >= a2 ? a1 : a2);
            answer[1] = (a1 < a2 ? a1 : a2);
            break;
        }
    }
    return answer;
}