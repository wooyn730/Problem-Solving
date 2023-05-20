#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, vector<int> query) {
    vector<int> answer;
    
    for (int i=0; i<query.size(); i++)
    {
        if (i%2 == 0)
        {
            for (int j=0; j<arr.size(); j++)
            {
                if (j <= query[i])
                    answer.push_back(arr[j]);
            }
        }
        else
        {
            for (int j=0; j<arr.size(); j++)
            {
                if (j >= query[i])
                    answer.push_back(arr[j]);
            }
        }
        
        arr = answer;
        answer.clear();
    }
    
    return arr;
}