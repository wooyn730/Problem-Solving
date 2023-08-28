#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, vector<vector<int>> queries) {
    vector<int> answer;
    for (int i=0; i<queries.size(); i++)
    {
        int ans = -1;
        for (int j=queries[i][0]; j<= queries[i][1]; j++)
        {
            if (arr[j] > queries[i][2])
            {
                if (ans == -1)
                    ans = arr[j];
                else
                {
                    if (arr[j] < ans)
                        ans = arr[j];
                }
            } 
        }
        answer.push_back(ans);
    }
    return answer;
}