#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> rank, vector<bool> attendance) {
    vector<pair<int, int>> student;
    
    for (int i=0; i<rank.size(); i++)
        if (attendance[i])
            student.push_back(make_pair(rank[i], i));
    
    sort(student.begin(), student.end());
    return student[0].second*10000 + student[1].second*100 + student[2].second;
}