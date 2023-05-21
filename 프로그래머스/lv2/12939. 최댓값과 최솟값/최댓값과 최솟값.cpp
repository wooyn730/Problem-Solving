#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string s) {
    string answer = "";
    string tmp = "";
    vector <int> nums;
    
    for (int i=0; i<s.length(); i++)
    {
        if (s[i] != ' ')
        {
            tmp += s[i];
        }
        else
        {
            nums.push_back(stoi(tmp));
            tmp = "";
        }
    }
    nums.push_back(stoi(tmp));
    sort(nums.begin(), nums.end());
    
    return (to_string(nums.front()) + " " + to_string(nums.back()));
}