#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    priority_queue<int, vector<int>, greater<int>> hot;
    for (int i=0; i<scoville.size(); i++)
        hot.push(scoville[i]);
    
    int answer = 0;
    while (hot.top() < K)
    {
        if (hot.size() == 1)
        {
            answer = -1;
            break;
        }
        int mix = hot.top();
        hot.pop();
        mix += hot.top() * 2;
        hot.pop();
        
        hot.push(mix);
        answer++;
    }
    
    return answer;
}