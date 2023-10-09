#include <string>
#include <vector>

using namespace std;

string solution(string my_string) {
    string answer = "";
    for (int i=0; i<my_string.length(); i++)
    {
        bool isDup = false;
        for (int j=0; j<i; j++)
        {
            if (my_string[j] == my_string[i])
            {
                isDup = true;
                break;
            }
        }
        if (!isDup)
            answer += my_string[i];
    }
    
    return answer;
}