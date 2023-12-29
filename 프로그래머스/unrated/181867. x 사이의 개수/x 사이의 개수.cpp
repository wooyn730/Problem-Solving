#include <string>
#include <vector>

using namespace std;

vector<int> solution(string myString) {
    vector<int> answer;
    int x = 0;
    for (int i=0; i<myString.length(); i++)
    {
        if (myString[i]=='x')
        {
            answer.push_back(x);
            x = 0;
        }
        else
            x++;
    }
    answer.push_back(x);
    return answer;
}