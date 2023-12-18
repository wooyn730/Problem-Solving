#include <string>
#include <vector>

using namespace std;

vector<string> solution(string my_string) {
    vector<string> answer;
    my_string += " ";
    int idx=0;
    for (int i=0; i<my_string.length(); i++)
    {
        if (my_string[i]==' ')
        {
            answer.push_back(my_string.substr(idx, i-idx));
            idx = i+1;
        }
    }
    return answer;
}