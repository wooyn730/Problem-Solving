#include <string>
#include <vector>

using namespace std;

string solution(string s, string skip, int index) {
    string answer = "";
    vector<bool> skipChar(26);
    
    for (int i=0; i<skip.length(); i++)
    {
        skipChar[skip[i]-'a'] = true;
    }
    
    for (int i=0; i<s.length(); i++)
    {
        int tmp = index;
        while (tmp--)
        {
            if (skipChar[(s[i]-'a'+1)%26])
                tmp++;
            s[i]++;
            
            if (s[i] > 'z')
                s[i] = 'a';
        }
        answer += s[i];
    }
    
    return answer;
}