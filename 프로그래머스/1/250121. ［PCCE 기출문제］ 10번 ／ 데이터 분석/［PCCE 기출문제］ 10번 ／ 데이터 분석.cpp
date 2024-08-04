#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int sortNum;

int GetIdx(string str)
{
    if (str == "code")
        return 0;
    else if (str == "date")
        return 1;
    else if (str == "maximum")
        return 2;
    else if (str == "remain")
        return 3;
}

bool compare(vector<int> a, vector<int> b)
{
    return a[sortNum] < b[sortNum];
}

vector<vector<int>> solution(vector<vector<int>> data, string ext, int val_ext, string sort_by) {
    vector<vector<int>> answer;
    int extNum = GetIdx(ext);
    for (int i=0; i<data.size(); i++)
    {
        if (data[i][extNum] < val_ext)
            answer.push_back(data[i]);
    }
    
    sortNum = GetIdx(sort_by);
    sort(answer.begin(), answer.end(), compare);
    
    return answer;
}