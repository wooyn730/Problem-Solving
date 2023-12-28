#include <string>
using namespace std;

string solution(string my_string) {
    string answer = "";
    for (int i=0; i<my_string.length(); i++)
    {
        if (my_string[i]<97)
            answer += tolower(my_string[i]);
        else
            answer += toupper(my_string[i]);
    }
    return answer;
}