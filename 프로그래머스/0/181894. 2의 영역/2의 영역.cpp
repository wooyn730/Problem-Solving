#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    int minIdx=arr.size(), maxIdx=-1;
    
    for (int i=0; i<arr.size(); i++)
    {
        if (arr[i]==2)
        {
            if (i<minIdx)
                minIdx = i;
            if (i>maxIdx)
                maxIdx = i;
        }
    }
    
    for (int i=minIdx; i<=maxIdx; i++)
        answer.push_back(arr[i]);
    if (answer.empty())
        answer.push_back(-1);
    return answer;
}