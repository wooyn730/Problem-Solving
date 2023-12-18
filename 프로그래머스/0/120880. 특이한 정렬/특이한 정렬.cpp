#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
    if (a.first == b.first)
        return a.second > b.second;
    return
        a.first < b.first;
}
vector<int> solution(vector<int> numlist, int n) {
    vector<int> answer;
    vector<pair<int,int>> diff;
    
    for (int i=0; i<numlist.size(); i++)
        diff.push_back(make_pair(abs(numlist[i]-n), numlist[i]));
    
    sort(diff.begin(), diff.end(), compare);
    for (int i=0; i<numlist.size(); i++)
        answer.push_back(diff[i].second);
    
    return answer;
}