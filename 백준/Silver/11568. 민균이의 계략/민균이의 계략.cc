#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<int> nums(N);
    for (int i = 0; i < N; i++)
            cin >> nums[i];

    vector<int> maxNum(N, 1); // maxNum[i]는 nums[i]를 마지막 원소로 하는 증가수열 길이

    for (int i = 1; i < N; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (nums[j] < nums[i])
                maxNum[i] = max(maxNum[i], maxNum[j] + 1);
        }
    }

    cout << *max_element(maxNum.begin(), maxNum.end());
    return 0;
}