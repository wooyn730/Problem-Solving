#include <string>
#include <vector>

using namespace std;

vector<string> solution(string myStr) {
    vector<string> answer;
    vector<int> jump;
    
    myStr = 'a' + myStr + 'a';
    for (int i=0; i<myStr.length(); i++)
        if (myStr[i] == 'a' || myStr[i] == 'b' || myStr[i] == 'c')
            jump.push_back(i);
    
    for (int i=0; i<jump.size()-1; i++)
        if (jump[i+1]-jump[i] > 1)
            answer.push_back(myStr.substr(jump[i]+1, jump[i+1]-jump[i]-1));

    if (answer.empty())
        answer.push_back("EMPTY");
    return answer;
}