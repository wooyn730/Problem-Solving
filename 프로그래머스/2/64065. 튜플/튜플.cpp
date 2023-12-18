#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(string a, string b)
{
    return a.size() < b.size();
}

vector<int> solution(string s) {
    vector<string> sets;
    
    string tmp;
    bool isSet = false;
    for (int i=1; i<s.length()-1; i++)
    {
        if (s[i] == '{')
        {
            tmp = "";
            isSet = true;
        }
        else if (s[i] == '}')
        {
            sets.push_back(tmp);
            isSet = false;
        }
        else if (isSet)
        {
            tmp += s[i];
        }
    }
    
    // 집합 내 원소 하나씩 구하기
    sort(sets.begin(), sets.end(), compare);
    vector<int> answer;
    for (int i=0; i<sets.size(); i++)
    {
        vector<int> element;
        tmp = "";
        for (int j=0; j<sets[i].length(); j++)
        {
            if (sets[i][j] == ',')
            {
                element.push_back(stoi(tmp));
                tmp = "";
            }
            else
            {
                tmp += sets[i][j];
            }
        }
        element.push_back(stoi(tmp));
        
        for (int j=0; j<element.size(); j++)
        {
            bool isDup = false;
            
            for (int k=0; k<answer.size(); k++)
                if (element[j] == answer[k])
                    isDup = true;

            if (!isDup)
                answer.push_back(element[j]);
        }
    }
    return answer;
}