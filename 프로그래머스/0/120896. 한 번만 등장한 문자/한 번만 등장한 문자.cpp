#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string s) {
    string answer = "";
    sort(s.begin(), s.end());
    for (int i=0; i<s.length(); i++)
        if ((i==0 && s[i]!=s[i+1]) || (i==s.length()-1 && s[i-1]!=s[i]) || (s[i-1]!=s[i]&&s[i]!=s[i+1]))
            answer += s[i];
    return answer;
}