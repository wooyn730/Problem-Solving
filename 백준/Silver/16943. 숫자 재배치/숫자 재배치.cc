#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int A, B;
bool visited[10];
vector<int> nums;
int answer = -1;

void GetBiggestNum(int size, int sum)
{
    if (size == nums.size())
    {
        if (sum > answer && sum < B)
            answer = sum;
        return;
    }

    for (int i = 0; i < nums.size(); i++)
    {
        if (size == 0 && nums[i] == 0) continue;
        if (visited[i]) continue;

        visited[i] = true;
        GetBiggestNum(size + 1, sum*10 + nums[i]);
        visited[i] = false;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> A >> B;

    while (A > 0)
    {
        nums.push_back(A % 10);
        A /= 10;
    }
    sort(nums.begin(), nums.end());

    GetBiggestNum(0, 0);

    cout << answer;

    return 0;
}
