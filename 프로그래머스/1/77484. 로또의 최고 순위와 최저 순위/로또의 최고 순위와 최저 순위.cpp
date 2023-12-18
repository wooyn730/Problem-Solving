#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    int matchedNum = 0;
    int possibleNum = 0;
    
    for (int i=0; i<6; i++)
    {
        if (lottos[i] == 0)
            possibleNum++;
        else
        {
            for (int j=0; j<6; j++)
            {
                if (lottos[i] == win_nums[j])
                {
                    matchedNum++;
                    break;
                }
            }
        }
    }
    if (matchedNum+possibleNum>1)
        answer.push_back(7-(matchedNum+possibleNum));
    else
        answer.push_back(6);
    
    if (matchedNum>1)
        answer.push_back(7-matchedNum);
    else
        answer.push_back(6);
    
    return answer;
}