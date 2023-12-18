#include <string>
#include <vector>
#include <cmath> //ceil(): 올림, floor(): 내림

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int day = 0;
    
    for (int i=0; i<progresses.size(); i++)
    {
        int daywait = ceil((double)(100 - progresses[i])/speeds[i]) ;
        
        if (day < daywait)
        {
            answer.push_back(1);
            day = daywait;
        }
        else
            answer[answer.size()-1]++;
    }
    return answer;
}