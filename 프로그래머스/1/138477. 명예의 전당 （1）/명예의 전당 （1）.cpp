#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int k, vector<int> score) {
    vector<int> answer;
    vector<int> tmp;
    
    for (int i=0; i<score.size(); i++)
    {
        tmp.push_back(score[i]);
        sort(tmp.begin(), tmp.end());
        reverse(tmp.begin(), tmp.end());
        
        if (i<k)
            answer.push_back(tmp[i]);
        else
            answer.push_back(tmp[k-1]);
    }
    
    return answer;
}