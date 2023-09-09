#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<string, int>&a, pair<string, int>&b)
{
    return a.second < b.second; // 오름차순
}

int solution(int cacheSize, vector<string> cities) {
    
    if (cacheSize == 0)
        return cities.size()*5;
    
    vector<pair<string,int>> cache;
    int answer = 0;
    for (int i=0; i<cities.size(); i++)
    {
        for (int j=0; j<cities[i].length(); j++)
            cities[i][j] = tolower(cities[i][j]); // 대소문자 구분x
        
        bool isExist = false;
        for (int j=0; j<cache.size(); j++)
        {
            if (cache[j].first == cities[i])
            {
                cache[j].second = i;
                isExist = true;
                answer++;
                break;
            }
        }
        if (!isExist)
        {
            if (cache.size()<cacheSize)
            {
                cache.push_back(make_pair(cities[i], i));
            }
            else
            {
                sort(cache.begin(), cache.end(), compare);
                cache[0].first = cities[i];
                cache[0].second = i;
            }
            answer += 5;
        }
    }
    return answer;
}