#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> emergency) {
    vector<int> sort_e(emergency);
    sort(sort_e.rbegin(), sort_e.rend());
    vector<int> answer;
    for (int i=0; i<emergency.size(); i++)
    {
        for (int j=0; j<emergency.size(); j++)
        {
            if (emergency[i] == sort_e[j])
            {
                answer.push_back(j+1);
                break;
            }
        }
    }
    return answer;
}