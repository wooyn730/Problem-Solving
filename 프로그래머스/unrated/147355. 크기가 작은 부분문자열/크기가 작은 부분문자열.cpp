#include <string>
#include <vector>

using namespace std;

int solution(string t, string p) {
    int answer = 0;
    long long num1 = 0;
    long long num2 = 0;
    
    num2 = stoll(p);
    
    for (int i=0; i<=t.length()-p.length(); i++)
    {
        string tmp = "";
        
        for (int j=i; j<i+p.length(); j++)
            tmp += t[j];
        
        num1 = stoll(tmp);
        
        if (num1 <= num2)
            answer++;
    }
    
    return answer;
}