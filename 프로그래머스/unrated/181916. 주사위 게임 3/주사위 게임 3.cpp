#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

bool compare(pair<int, int> &a, pair<int, int> &b)
{
    if (a.second == b.second)
        return a.first < b.first;
    return a.second < b.second;
}

int solution(int a, int b, int c, int d) {
    int num[4];
    num[0] = a;
    num[1] = b;
    num[2] = c;
    num[3] = d;
    
    map<int, int> map;
    for (int i=0; i<4; i++)
    {
        if (map.find(num[i])!=map.end())
            map[num[i]]++;
        else
            map.insert({num[i], 1});
    }
    
    vector<pair<int, int>> vec(map.begin(), map.end());
    sort(vec.begin(), vec.end(), compare);
    
    switch(vec.size())
    {
        case 1:
            return 1111 * vec[0].first;
        case 2:
            if (vec[1].second == 3)
                return pow((10 * vec[1].first + vec[0].first), 2);
            else
                return (vec[1].first + vec[0].first) * (vec[1].first - vec[0].first);
        case 3:
            return vec[0].first * vec[1].first;
        case 4:
            return vec[0].first;
    }
}