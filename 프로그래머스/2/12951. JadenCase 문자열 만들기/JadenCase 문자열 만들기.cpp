#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    bool doUpper;
    
    for (int i=0; i<s.length(); i++)
    {
        doUpper = false;
        
        if (i==0 || s[i-1] == ' ')
            doUpper = true;
        
        answer += ( doUpper ? toupper(s[i]) : tolower(s[i]) );
    }
    
    return answer;
}