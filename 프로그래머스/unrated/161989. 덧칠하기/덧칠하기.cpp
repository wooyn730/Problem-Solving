#include <string>
#include <vector>

using namespace std;

int solution(int n, int m, vector<int> section) {
    int answer = 0;
    vector<int> tmp;

    //tmp.clear();
    
    while (1)
    {
        tmp.clear();
        answer++;
        for (int j=0; j<section.size(); j++)
        {
            if (section[j] > section.front()+m-1) // 가장 앞쪽부터 한 번 칠하고 못칠한 부분 저장
            {
                tmp.push_back(section[j]);
            }
        }
    
        if (tmp.empty())
            break;
        
        section = tmp;
    }
    
    return answer;
}