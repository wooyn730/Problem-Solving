#include <string>
#include <stack>

using namespace std;

bool solution(string s)
{
    stack<int> stack;

    for (int i=0; i<s.length(); i++)
    {
        if (s[i] == '(')
            stack.push('(');
        else
        {
            if (stack.empty())
                return false;
            else
                stack.pop();
        }
    }
    
    return stack.empty() ? true : false;
}