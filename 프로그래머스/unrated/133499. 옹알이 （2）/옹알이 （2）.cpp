#include <string>
#include <vector>
#include <regex>

using namespace std;

int solution(vector<string> babbling) {
    int answer = 0;
    
    for (int i=0; i<babbling.size(); i++)
    {
        // 문자 => 숫자로 치환
        babbling[i] = regex_replace(babbling[i], regex("aya"), "1");
        babbling[i] = regex_replace(babbling[i], regex("ye"), "2");
        babbling[i] = regex_replace(babbling[i], regex("woo"), "3");
        babbling[i] = regex_replace(babbling[i], regex("ma"), "4");
        
        // 연속된 중복 숫자 체크
        bool isDup = false;
        for (int j=1; j<babbling[i].length(); j++)
            if (babbling[i][j] >= '1' && babbling[i][j] <= '4')
                if (babbling[i][j-1] == babbling[i][j])
                    isDup = true;

        if (!isDup)
        {
            babbling[i] = regex_replace(babbling[i], regex("1"), "");
            babbling[i] = regex_replace(babbling[i], regex("2"), "");
            babbling[i] = regex_replace(babbling[i], regex("3"), "");
            babbling[i] = regex_replace(babbling[i], regex("4"), "");
        
            if (babbling[i] == "")
                answer++;
        }
    }
    
    return answer;
}