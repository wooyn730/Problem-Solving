#include <string>
#include <vector>
#include <set>
#include <algorithm> // find

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer(2);
    set<string> w;
    
    w.insert(words[0]);
    for (int i=1; i<words.size(); i++)
    {
        if (words[i-1][words[i-1].size()-1] == words[i][0]) // 끝말잇기
        {
            if (w.find(words[i]) == w.end()) // 중복 x
                w.insert(words[i]);
            else // 중복 o
            {
                answer[0] = i%n+1; // 탈락자 번호
                answer[1] = i/n+1; // 탈락자의 차례
                return answer;
            }
        }
        else // 끝말잇기 실패
        {
            answer[0] = i%n+1;
            answer[1] = i/n+1;
            return answer;
        }
    }
    return answer;
}
