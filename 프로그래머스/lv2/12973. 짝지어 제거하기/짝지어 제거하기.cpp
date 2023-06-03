#include <string>
#include <stack>

using namespace std;

int solution(string s)
{
    stack<int> stack;
    for (int i=0; i<s.length(); i++)
    {
        if (!stack.empty() && stack.top() == s[i])
            stack.pop();
        else
            stack.push(s[i]);
    }
    
    return stack.empty() ? 1 : 0;
}