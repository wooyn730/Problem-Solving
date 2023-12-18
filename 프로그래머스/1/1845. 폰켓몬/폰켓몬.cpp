#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> nums)
{
    int N = nums.size()/2;
    sort(nums.begin(), nums.end());
    nums.erase(unique(nums.begin(), nums.end()), nums.end());
    
    return (nums.size() > N ? N : nums.size());
}