#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(string s) {
    stack<char> stack;
    int answer = 0;
    int T= s.length();
    while (T--)
    {
        bool isRight = true;
        for (int i=0; i<s.length(); i++)
        {
            if (!isRight)
                break;
            switch(s[i])
            {
                case '[':
                case '(':
                case '{':
                    stack.push(s[i]);
                    break;
                case ']':
                    if (stack.top() == '[')
                        stack.pop();
                    else
                        isRight = false;
                    break;
                case ')':
                    if (stack.top() == '(')
                        stack.pop();
                    else
                        isRight = false;
                    break;
                case '}':
                    if (stack.top() == '{')
                        stack.pop();
                    else
                        isRight = false;
                    break;
            }
        }
        if (isRight && stack.empty())
            answer++;
        
        s = s.substr(1, s.length()-1) + s[0];
    }
    
    return answer;
}