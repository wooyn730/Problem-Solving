#include <string>
#include <vector>

using namespace std;

int solution(vector<int> ingredient) {
    int answer = 0;
    vector<int> hamberger;
    
    for (int i=0; i<ingredient.size(); i++)
    {
        hamberger.push_back(ingredient[i]);
        
        if (hamberger.size()>=3 && hamberger[hamberger.size()-1] == 1 && hamberger[hamberger.size()-2] == 3 && hamberger[hamberger.size()-3] == 2 && hamberger[hamberger.size()-4] == 1)
        {
            for (int j=0; j<4; j++)
                hamberger.pop_back();
            answer++;
        }
    }
    return answer;
}