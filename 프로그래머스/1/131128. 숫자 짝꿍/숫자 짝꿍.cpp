#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string X, string Y) {
    string answer = "";
    vector<int> nums1;
    vector<int> nums2;
    
    for (int i=0; i<X.length(); i++)
        nums1.push_back(X[i]-'0');
    sort(nums1.begin(), nums1.end());
    
    for (int i=0; i<Y.length(); i++)
        nums2.push_back(Y[i]-'0');
    sort(nums2.begin(), nums2.end());
    
    int idx1 = nums1.size()-1;
    int idx2 = nums2.size()-1;
    
    while (idx1 >= 0 && idx2 >= 0)
    {
        if (nums1[idx1] == nums2[idx2])
        {
            answer += to_string(nums1[idx1]);
            idx1--;
            idx2--;
        }
        else if (nums1[idx1] < nums2[idx2])
            idx2--;
        else
            idx1--;
    }
    
    if (answer[0] == '0')
        answer = "0";
    
    return (answer == "" ? "-1" : answer);
}