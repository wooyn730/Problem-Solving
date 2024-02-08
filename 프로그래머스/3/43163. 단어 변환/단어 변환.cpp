#include <string>
#include <vector>
#include <queue>
using namespace std;

bool visit[51];

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    
    queue<pair<string, int>> q;
    q.push({begin, 0});
    
    while (!q.empty())
    {
        string word = q.front().first;
        int cnt = q.front().second;
        q.pop();
        
        if (word == target)
            answer = (answer == 0 ? cnt : (answer < cnt ? answer : cnt));
        
        for (int i=0; i<words.size(); i++)
        {
            if (visit[i])
                continue;
            
            int diff = 0;

            for (int j=0; j<word.length(); j++)
                if (words[i][j] != word[j])
                    diff++;

            if (diff == 1)
            {
                q.push({words[i], cnt + 1});
                visit[i] = true;
            }
        }
    }
    
    return answer;
}