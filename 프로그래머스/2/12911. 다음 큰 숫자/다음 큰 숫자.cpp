#include <string>

using namespace std;

int solution(int n) {
    pair<string, int> bin1;
    pair<string, int> bin2;
    bin1 = make_pair("", 0);
    bin2 = make_pair("", 0);
    
    int tmp = n;
    while (tmp>=1)
    {
        char t = tmp%2==0 ? '0' : '1';
        bin1.first = t + bin1.first;
        
        if (t=='1')
            bin1.second++;
            
        tmp/=2;
    }
    
    for (int i=n+1; ; i++)
    {
        tmp = i;
        bin2.second = 0;
        
        while (tmp>=1)
        {
            if (tmp%2==1)
                bin2.second++;
            tmp/=2;
        }
        
        if (bin1.second == bin2.second)
            return i;
    }
}