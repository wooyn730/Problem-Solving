#include <iostream>
#include <set>
#include <cmath>
#include <algorithm>
using namespace std;

int n, k;
int nums[10];
bool visited[10];
set<long long> canMake;

void Choice(long long sum, int maxIdx)
{
    if (maxIdx == k)
    {
        canMake.insert(sum);
        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            visited[i] = true;
            long long newSum = nums[i] >= 10 ? sum * 100 + nums[i] : sum * 10 + nums[i];
            Choice(newSum, maxIdx + 1);
            visited[i] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;

    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    Choice(0, 0);

    cout << canMake.size();
    return 0;
}