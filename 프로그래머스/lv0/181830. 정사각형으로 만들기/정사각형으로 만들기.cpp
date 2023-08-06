#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr) {
    int a = arr.size();
    int b = arr[0].size();
    
    if (a > b)
    {
        for (int i=0; i<a; i++)
        {
            for (int j=0; j<a-b; j++)
                arr[i].push_back(0);
        }
    }
    else if (b > a)
    {
        for (int i=0; i<b-a; i++)
        {
            arr.push_back(vector<int>());
            for (int j=0; j<b; j++)
                arr[arr.size()-1].push_back(0);
        }
    }
    return arr;
}