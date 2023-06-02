#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer(2);
    
    while (s.length() > 1)
    {
        int tmp = 0; // 1 개수
        
        for (int i=0; i<s.length(); i++)
        {
            if (s[i]=='0')
                answer[1]++;
            else
                tmp++;
        }

        s = "";
        while (tmp > 0)
        {
            char t = tmp%2 == 0 ? '0' : '1';
            s = t + s;
            tmp /= 2;
        }
        answer[0]++;
    }
    
    return answer;
}