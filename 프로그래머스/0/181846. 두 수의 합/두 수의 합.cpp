#include <string>
#include <vector>

using namespace std;

string solution(string a, string b) {
    string ans = "";
    bool isCarry = false;
    while (true)
    {
        int A = (a.length() > 0 ? a[a.length()-1]-'0' : 0);
        int B = (b.length() > 0 ? b[b.length()-1]-'0' : 0);
        int k = A + B;
        
        if (isCarry)
            k += 1;
        
        if (k>=10)
        {
            k%=10;
            isCarry=true;
        }
        else
            isCarry=false;
        ans = to_string(k) + ans;
        
        a = a.substr(0, a.length()-1);
        b = b.substr(0, b.length()-1);
        
        if (a=="" && b=="")
        {
            if (isCarry)
                ans = "1" + ans;
            break;
        }
    }
    return ans;
}