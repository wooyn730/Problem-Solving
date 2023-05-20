#include <string>
#include <vector>

using namespace std;

int solution(string t, string p) {
    int answer = 0;
    long long num1 = 0;
    long long num2 = 0;
    
    //num2 = stoll(p); //안되는 이유?
    for (int i=0; i<p.length(); i++)
    {
        num2 *= 10;
        num2 += p[i];
    }
    
    for (int i=0; i<=t.length()-p.length(); i++)
    {
        num1 = 0;
        for (int j=i; j<i+p.length(); j++)
        {
            num1 *= 10;
            num1 += t[j];
        }
        
        if (num1 <= num2)
            answer++;
    }
    
    return answer;
}