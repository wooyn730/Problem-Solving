#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    int xCnt = 0;
    int yCnt = 0;
    bool isFirst = true;
    char xChar;
    
    for (int i=0; i<s.length(); i++)
    {
        if (isFirst)
        {
            xChar = s[i];
            xCnt++;
            isFirst = false;
            
            if (i == s.length()-1)
                answer++;
        }
        else
        {
            if (s[i] == xChar)
                xCnt++;
            else
                yCnt++;
            
            // 비교
            if (xCnt == yCnt)
            {
                answer++;
                isFirst = true;
                xCnt = 0;
                yCnt = 0;
            }
            else
            {
                if (i == s.length()-1)
                    answer++;
            }
        }
    }
    return answer;
}