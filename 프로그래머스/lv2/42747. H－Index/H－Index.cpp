#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    sort(citations.rbegin(), citations.rend());
    int answer = citations.size();
    while (true)
    {
        int hCnt = 0;
        for (int i=0; i<citations.size(); i++)
        {
            if (citations[i]>=answer)
                hCnt++;
            else
                break;
        }
        
        if (hCnt >= answer)
            break;
        else
            answer--;
    }
    
    return answer;
}