#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<vector<int>> score) {
    int siz = score.size();
    vector<int> answer(siz);
    vector<double> av(siz);
    
    for (int i=0; i<siz; i++)
        av[i] = (double)(score[i][0] + score[i][1]) / 2;

    vector<double> av2(av);
    
    sort(av2.rbegin(), av2.rend());
    
    for (int i=0; i<siz; i++)
    {
        for (int j=0; j<siz; j++)
        {
            if (av[i] == av2[j])
            {
                answer[i] = j+1;
                break;
            }
        }
    }
    return answer;
}