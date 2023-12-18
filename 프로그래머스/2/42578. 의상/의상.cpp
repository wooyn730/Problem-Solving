#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    map<string, int> map;
    for (int i=0; i<clothes.size(); i++)
    {
        if (map.find(clothes[i][1]) != map.end())
            map[clothes[i][1]]++;
        else
            map.insert({clothes[i][1], 1});
    }

    for (auto iter : map)
    {
        answer *= (iter.second + 1);
    }
    
    return --answer;
}