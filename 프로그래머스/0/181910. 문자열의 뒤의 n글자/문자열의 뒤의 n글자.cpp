#include <string>
#include <vector>

using namespace std;

string solution(string mystring, int n) {
    if (n >= mystring.length())
        return mystring;
    
    string answer = "";
    for (int i=mystring.length()-1; i>mystring.length()-1-n; i--)
        answer = mystring[i] + answer;
    return answer;
}