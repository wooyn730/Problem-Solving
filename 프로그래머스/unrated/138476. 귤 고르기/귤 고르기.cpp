#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b)
{
    return a.second > b.second;
}

int solution(int k, vector<int> tangerine) {
    vector<pair<int, int>> t;
    int answer = 0;
    
    for (int i=0; i<tangerine.size(); i++)
    {
        bool exist = false;
        for (int j=0; j<t.size(); j++)
        {
            if (t[j].first == tangerine[i])
            {
                t[j].second++;
                exist = true;
                break;
            }
        }
        if (!exist)
            t.push_back(make_pair(tangerine[i], 1));
    }
    
    sort(t.begin(), t.end(), compare);
    
    for (int j=0; j<t.size(); j++)
    {
        if (k <= 0)
            break;
        k -= t[j].second;
        answer++;
    }
    return answer;
}