#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    vector<char> letter;
    vector<int> letter_idx;
    bool haveLetter;
    
    for (int j=0; j<s.length(); j++)
    {
        haveLetter = false;
        for (int k=0; k<letter.size(); k++)
        {
            if (letter[k] == s[j])
            {
                answer.push_back(j-letter_idx[k]);
                letter_idx[k] = j;
                haveLetter = true;
            }
        }
        if (!haveLetter)
        {
            answer.push_back(-1);
            letter.push_back(s[j]);
            letter_idx.push_back(j);
        }  
    }
    return answer;
}