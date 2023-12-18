#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int k, int m, vector<int> score) {
    int answer = 0;
    vector<int> box;
    
    sort(score.begin(), score.end());
    reverse(score.begin(), score.end());
    
    for (int i=0; i<score.size(); i++)
    {
        box.clear();
        for (int j=0; j<m; j++)
        {
            box.push_back(score[i+j]);
        }
        if (box.size() == m)
        {
            answer += box.back()*m;
            i += m-1;
        }
    }
    
    return answer;
}