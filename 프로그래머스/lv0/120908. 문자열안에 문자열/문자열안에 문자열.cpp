#include <string>
#include <vector>

using namespace std;

int solution(string str1, string str2) {
    if (str1.length() < str2.length())
        return 2;
    
    for (int i=0; i<=str1.length()-str2.length(); i++)
    {
        if (str1.substr(i, str2.length()) == str2)
            return 1;
    }
    return 2;
}