#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer;
    
    // 어떤 키들이 있는지, 각 키들의 최소값이 무엇인지 저장
    vector<int> keys(26);
    
    for (int i=0; i<keymap.size(); i++)
    {
        for (int j=0; j<keymap[i].length(); j++)
        {
            if (keys[keymap[i][j]-'A'] == 0 || j+1 < keys[keymap[i][j]-'A'])
                keys[keymap[i][j]-'A'] = j+1;
        }
    }
    
    for (int i=0; i<targets.size(); i++)
    {
        answer.push_back(0);
        for (int j=0; j<targets[i].length(); j++)
        {
            if (keys[targets[i][j]-'A'] == 0)
            {
                answer[i] = -1;
                break;
            }
            answer[i] += keys[targets[i][j]-'A'];
        }
    }
    
    return answer;
}